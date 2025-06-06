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
    int maxi=-10000;
    int f(TreeNode* root){
        if(!root)return 0;

        int left=0,right=0;

        if(root->left)left=f(root->left);

        if(root->right)right=f(root->right);

        maxi=max(maxi,root->val+left+right);
        return max( 0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        f(root);
        return maxi;
    }
};