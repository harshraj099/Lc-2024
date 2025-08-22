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
     int f(TreeNode* root, long long &prev){
      if(!root)return 1; 

      int left=f(root->left,prev); 
      if(!left)return left;
 
     if(prev>=root->val)return 0; 
    prev=root->val;

      int right=f(root->right,prev);
        if(!right)return right; 

        return left&right;
    }
    bool isValidBST(TreeNode* root) {
        long long prev=-1e11;
        return f(root,prev);
    }
};