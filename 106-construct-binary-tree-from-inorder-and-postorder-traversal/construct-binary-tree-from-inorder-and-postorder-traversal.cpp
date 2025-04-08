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
    TreeNode* f(int ps,int pe,vector<int>& postorder,int is,int ie, vector<int>& inorder,map<int,int>&m){
        if(ps>pe || is>ie)return NULL;

        TreeNode * node=new TreeNode(postorder[pe]);
        
        node->left=f(ps,ps+m[postorder[pe]]-is-1,postorder,is,m[postorder[pe]]-1,inorder,m);
        node->right=f(ps+m[postorder[pe]]-is,pe-1,postorder,m[postorder[pe]]+1,ie,inorder,m);

        return node;
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int>m;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
       return f(0,n-1,postorder,0,n-1,inorder,m);
    }
};