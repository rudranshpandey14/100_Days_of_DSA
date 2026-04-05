/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countLeafNodes(struct TreeNode* root) {
    // Base case: empty tree
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recur for left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
