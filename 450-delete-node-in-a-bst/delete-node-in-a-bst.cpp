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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val==key){
            if(!root->left)return root->right;
            if(!root->right)return root->left;

            TreeNode* dummy=root->right;
            while(dummy->left)dummy=dummy->left;
            dummy->left=root->left;

            return root->right;
        }

        if(root->val<key)root->right=deleteNode(root->right,key);
       else root->left=deleteNode(root->left,key);

        return root;
    }
};