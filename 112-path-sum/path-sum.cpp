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
    bool f(TreeNode* root, int t) {
        if(!root->left && !root->right){
            if(root->val==t)return true;
            return false;
        }

        if(root->left){
            root->left->val=root->val+root->left->val;
            if(f(root->left,t))return true;
        }
         if(root->right){
            root->right->val=root->val+root->right->val;
            if(f(root->right,t))return true;
        }
            return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
       return f(root,targetSum);
    }
};