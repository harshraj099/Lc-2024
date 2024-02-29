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
        bool dfs(TreeNode* root,vector<int>&parent,int level){
            if(root==NULL)return true;
            if(level%2!=0 && parent[level]==-1){
                if(root->val%2==0)parent[level]=root->val;
                else return false;}
           else if(level%2==0 && parent[level]==-1){
               if(root->val%2!=0)parent[level]=root->val;
               else return false;}
            // cout<<level<<"->"<<parent[level]<<endl;
           else if(level%2!=0 && parent[level]!=-1){
                if(root->val%2==0 && parent[level]>root->val)parent[level]=root->val;
                else return false;
            }
           else  if(level%2==0 && parent[level]!=-1){
                if(root->val%2!=0 && parent[level]<root->val)parent[level]=root->val;
                else return false;
            }

            if(!dfs(root->left,parent,level+1))return false;
            if(!dfs(root->right,parent,level+1))return false;

            return true;
        }
    bool isEvenOddTree(TreeNode* root) {
        vector<int>parent(1e5,-1);
      return  dfs(root,parent,0);
    }
};