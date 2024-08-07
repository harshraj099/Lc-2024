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
        TreeNode* getright(TreeNode* root){
            if(!root)return NULL;
            if(!root->right )return root;
           return getright(root->right);
        }
    TreeNode* del(TreeNode* root, int key,TreeNode* prev){
        if(!root)return nullptr;

        if(root->val==key){
            if(!root->right && !root->left){
            return NULL;
            }
           TreeNode* right=getright(root->left); // root->right ka leftmost nikalo aur root->left se connect kerdo
            if(!right){
                return root->right;
            }
            else {
                 right->right=root->right;
                return root->left;
            }
        }
       root->left=del(root->left,key,root);
       root->right=del(root->right,key,root);
       return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(!root){
            return root;
        }
        
     return  del(root,key,NULL);

    }
};