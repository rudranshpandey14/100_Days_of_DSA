#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder Traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main() {
    int n, x, key;
    struct TreeNode* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Insert initial nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertIntoBST(root, x);
    }

    // Input value to insert
    scanf("%d", &key);

    // Insert new value
    root = insertIntoBST(root, key);

    // Output inorder traversal
    inorder(root);

    return 0;
}
