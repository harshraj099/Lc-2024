class Solution {
public:
    void inorder(TreeNode* root, int& prev, int& mini) {
        if (!root) return;

        // Traverse the left subtree
        inorder(root->left, prev, mini);

        // Update the minimum difference using the current node and the previous node
        if (prev != -1) {
            mini = min(mini, abs(root->val - prev));
        }
        // Update the previous node value
        prev = root->val;

        // Traverse the right subtree
        inorder(root->right, prev, mini);
    }

    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int prev = -1; // Initialize as -1 to indicate no previous node yet
        inorder(root, prev, mini);
        return mini;
    }
};
// 