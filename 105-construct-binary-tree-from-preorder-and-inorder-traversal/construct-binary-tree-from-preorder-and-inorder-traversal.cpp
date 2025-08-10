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
     TreeNode*f(vector<int>& preorder, vector<int>& inorder,int l,int r,int head, map<int,int>&m){
        if(l>r)return NULL;

         TreeNode* root=new TreeNode(preorder[head]);
         int ind =m[preorder[head]];
         root->left=f(preorder,inorder,l,ind-1,head+1,m);
         root->right=f(preorder,inorder,ind+1,r,ind-l+1+head,m);

         return root;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=0,r=inorder.size()-1;
        int head=0;
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)m[inorder[i]]=i;
        return f(preorder,inorder,l,r,head,m);
    }
};