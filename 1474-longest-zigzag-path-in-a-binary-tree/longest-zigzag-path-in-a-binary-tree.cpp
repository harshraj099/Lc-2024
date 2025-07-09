class Solution {
public:
    int maxLen = 0;

    void dfs(TreeNode* node, int direction, int length) {
        if (!node) return;
        maxLen = max(maxLen, length);
        if (direction == 0) {
            // Came from left, now go right
            dfs(node->left, 1, length + 1);  // left → right
            dfs(node->right, 0, 1);         // restart from right
        } else {
            // Came from right, now go left
            dfs(node->right, 0, length + 1); // right → left
            dfs(node->left, 1, 1);           // restart from left
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1, 1); // start going right
        dfs(root->right, 0, 1); // start going left
        return maxLen;
    }
};
