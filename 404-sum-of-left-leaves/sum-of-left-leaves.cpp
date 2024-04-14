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
        int value=0;
        void f(TreeNode* root,TreeNode* previous){
            if(root==NULL)return ;
            if(root->left==NULL && root->right==NULL && root==previous->left) {
                value+=root->val;
                }
          f(root->left,root);
           f(root->right,root);
            return ;
        }
    int sumOfLeftLeaves(TreeNode* root) {
        f(root,root);
        return value;
    }
};