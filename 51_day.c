/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: not found or found
    if (root == NULL || root->val == val) {
        return root;
    }

    // If value is smaller, search left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    // If value is greater, search right subtree
    else {
        return searchBST(root->right, val);
    }
}
