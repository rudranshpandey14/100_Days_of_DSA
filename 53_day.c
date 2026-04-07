#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Queue Node (for BFS with horizontal distance)
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Queue implementation
struct Queue {
    int front, rear, size;
    int capacity;
    struct QNode* array;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    q->array = (struct QNode*)malloc(capacity * sizeof(struct QNode));
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear].node = node;
    q->array[q->rear].hd = hd;
    q->size++;
}

struct QNode dequeue(struct Queue* q) {
    struct QNode item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);

    enqueue(q, root, 0);
    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct QNode temp = dequeue(q);
        struct TreeNode* curr = temp.node;

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root, int n) {
    if (!root) return;

    int offset = n; // to handle negative HD
    int** map = (int**)malloc((2*n) * sizeof(int*));
    int* count = (int*)calloc(2*n, sizeof(int));

    for (int i = 0; i < 2*n; i++) {
        map[i] = (int*)malloc(n * sizeof(int));
    }

    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int minHD = 0, maxHD = 0;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct TreeNode* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        map[index][count[index]++] = curr->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            enqueue(q, curr->left, hd - 1);

        if (curr->right)
            enqueue(q, curr->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root, n);

    return 0;
}
