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
    int f(TreeNode* root){
        if(root==NULL)return 0;
        int left=f(root->left);
        int right=f(root->right);
        return 1+max(left,right);
    }
    //  bool solve(TreeNode* root,int ht,int ct,int &ans){
    //      cout<<ct<<" ";
    //     if(root==NULL)return 0;
    //      if(ct==ht){ 
    //        ans= root->val;
    //        cout<<ans;
    //         return 1;
    //         }
    //     if(solve(root->left,ht,ct+1,ans))return 1;
    //      if(solve(root->right,ht,ct+1,ans))return 1;
    //     return 0;
    // }
    void solve(TreeNode* root,int ct,int &n,int &ans){
         cout<<ct<<" ";
        if(root==NULL)return ;
         if(ct>n){ 
             n=ct;
           ans= root->val;
           cout<<ans;
            }
        solve(root->left,ct+1,n,ans);
        solve(root->right,ct+1,n,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
    //    int height=f(root);
    //    cout<<height;
    //    int ans;
    //    solve(root,height,1,ans);

       int n=0;
       int ans;
        solve(root,1,n,ans);
       return ans;
    }
};