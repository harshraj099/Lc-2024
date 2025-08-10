/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, TreeNode* target, map<TreeNode*,TreeNode*>&m,TreeNode* prev){
        if(!root)return 0;
        m[root]=prev;
        if(root==target)return 1;
        if(f(root->left,target,m,root))return 1;
        if(f(root->right,target,m,root))return 1;
        return 0;
    }
    void solve(TreeNode* root, int k,map<TreeNode*,TreeNode*>&m,vector<int>&ans,TreeNode* prev){
        if(!root)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }

       if(root->left!=prev) solve(root->left,k-1,m,ans,root);
       if(root->right!=prev) solve(root->right,k-1,m,ans,root);
        if(m.find(root)!=m.end() && m[root]!=NULL  && m[root]!=prev)solve(m[root],k-1,m,ans,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;
       TreeNode* prev=NULL;
        f(root,target,m,prev);
        // find ele
        vector<int>ans;
        prev=NULL;
        solve(target,k,m,ans,prev);
        return ans;
    }
};