/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root) {
    // Base case
    if (root == NULL) {
        return 0;
    }

    // Recursive case
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}
