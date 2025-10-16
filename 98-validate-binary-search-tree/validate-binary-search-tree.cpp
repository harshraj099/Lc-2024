/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool v(TreeNode* n, long l, long h) {
        if (!n) return true;
        if (n->val <= l || n->val >= h) return false;
        return v(n->left, l, n->val) && v(n->right, n->val, h);
    }
    bool isValidBST(TreeNode* root) {
       return v(root, LONG_MIN, LONG_MAX);
    }
};