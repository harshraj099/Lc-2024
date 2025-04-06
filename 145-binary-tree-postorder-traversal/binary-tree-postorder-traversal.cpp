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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*>ans;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            ans.push(node);
            if(node->left)s.push(node->left);
            if(node->right)s.push(node->right);
        }
        vector<int>res;
        while(!ans.empty()){
             TreeNode* node=ans.top();
            ans.pop();
            res.push_back(node->val);
        }

        return res;
    }
};