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
    int f(TreeNode* root, int &k){
      if(!root)return 0; 
      int left=f(root->left,k); 
      if(left)return left; k--; 
      if(k==0)return root->val; 
      int right=f(root->right,k);
        if(right)return right; 
        return left|right;
    }
    int kthSmallest(TreeNode* root, int k) {
        return f(root,k);
    }
};