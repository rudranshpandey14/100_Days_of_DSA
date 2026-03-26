#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count occurrences of key
int countOccurrences(struct Node *head, int key) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, value, key;
    struct Node *head = NULL, *tail = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input linked list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Input key
    scanf("%d", &key);

    // Count and print occurrences
    printf("%d", countOccurrences(head, key));

    return 0;
}
