class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};  // {rob, not_rob}

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If we rob this node, we can't rob its children
        int rob = root->val + left.second + right.second;

        // If we don't rob this node, take max of robbing or not robbing each child
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
