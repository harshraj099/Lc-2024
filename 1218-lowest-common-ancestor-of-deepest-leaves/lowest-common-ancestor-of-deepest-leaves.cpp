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
    int f(TreeNode* root,map<TreeNode*,int>&m){
        if(!root)return 1;

        int left=f(root->left,m);
        int right=f(root->right,m);

        m[root]=max(left,right);
        return 1+max(left,right);
    }
    TreeNode* lca(TreeNode* root,map<TreeNode*,int>&m){
        if(!root)return NULL;
        if(!root->left && !root->right)return root;

        if(root->left && root->right && m[root->left]==m[root->right]) return root;

        if(root->left && root->right && m[root->left]>m[root->right]) return lca(root->left,m);
        if(root->left && root->right && m[root->left]<m[root->right]) return lca(root->right,m);

        if(!root->left) return lca(root->right,m);
        if(!root->right) return lca(root->left,m);

        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)return NULL;
        map<TreeNode*,int>m;
        f(root,m);

        return lca(root,m);
    }
};