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
    int f(TreeNode* root,int &ans){
        if(!root)return 0;
        int left=0,right=0;
        if(root->left && root->left->val==root->val)
        left=1+f(root->left,ans);
        if(root->right && root->right->val==root->val)
        right=1+f(root->right,ans);
        
        ans=max(ans,left+right);
        return 1+max(left,right);
    }
    int solve(TreeNode* root){
        if(!root)return 0;
        int ans=0;
        f(root,ans);
        return max({ans,solve(root->left),solve(root->right)});
    }
    int longestUnivaluePath(TreeNode* root) {
        return solve(root)/2;
    }
};