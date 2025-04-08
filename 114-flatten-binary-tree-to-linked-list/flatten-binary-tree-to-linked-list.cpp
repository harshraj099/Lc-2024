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
    TreeNode* f(TreeNode* root){
        if(!root)return NULL;

        TreeNode * left=f(root->left);
        TreeNode * right=f(root->right);
        TreeNode* temp=left;
        if(temp){
            root->left=NULL;
            root->right=temp;
            if(right){
                TreeNode* curr=temp;
                while(curr->right){
                    curr=curr->right;
                }
                curr->right=right;
            }
        }
        return root;
    }
    void flatten(TreeNode* root) {
         f(root);
    }
};