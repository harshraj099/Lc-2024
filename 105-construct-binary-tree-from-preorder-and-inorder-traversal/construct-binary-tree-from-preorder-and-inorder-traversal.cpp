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
    TreeNode* f(int ps,int pe,vector<int>& preorder,int is,int ie, vector<int>& inorder,map<int,int>&m){
        if(ps>pe || is>ie)return NULL;

        TreeNode * node=new TreeNode(preorder[ps]);
        
        node->left=f(ps+1,ps+m[preorder[ps]]-is,preorder,is,m[preorder[ps]]-1,inorder,m);
        node->right=f(ps+m[preorder[ps]]-is+1,pe,preorder,m[preorder[ps]]+1,pe,inorder,m);

        return node;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
       return f(0,n-1,preorder,0,n-1,inorder,m);
    }
};