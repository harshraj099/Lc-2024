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
     int f(TreeNode* root,long mini, long maxi){
      if(!root)return 1; 

        if(root->val>mini && root->val<maxi){
            int left=f(root->left,mini,root->val); 
            int right=f(root->right,root->val,maxi);

            return left&right;
        }
       else return 0;
    }
    bool isValidBST(TreeNode* root) {
        return f(root,-1e11,1e11);
    }
};