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

        void f(TreeNode* root){
            if(!root) return;

            f(root->left);
            f(root->right);

            TreeNode* temp=root->right;
            root->right=root->left;
             root->left=temp;
        }
    TreeNode* invertTree(TreeNode* root) {
        
        f(root);
        return root;
        
    }
};