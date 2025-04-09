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
    TreeNode* f(TreeNode* root, int key,TreeNode* prev,int left,int right){
        if(!root)return NULL;

        if(root->val==key){
            if(right){
                if(!root->left){
                  return  prev->right=root->right;
                }
                if(!root->right){
                  return  prev->right=root->left;
                }
                prev->right=root->left;
                 TreeNode* curr=root->left;
            while(curr->right){
                curr=curr->right;
            }
            curr->right=root->right;
            }
            else {
                 if(!root->left){
                  return  prev->left=root->right;
                }
                if(!root->right){
                  return  prev->left=root->left;
                }
                prev->left=root->left;
                 TreeNode* curr=root->left;
            while(curr->right){
                curr=curr->right;
            }
            curr->right=root->right;
            }

            return prev;
        }
        if(root->val<key){
            f(root->right,key,root,0,1);
        }
        else {
            f(root->left,key,root,1,0);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val==key){
            if(!root->right)return root->left;
            if(!root->left)return root->right;

            // TreeNode* temp=root->right;
            TreeNode* curr=root->left;
            while(curr->right){
                curr=curr->right;
            }
            curr->right=root->right;
            return root->left;
        }

       return f(root,key,root,0,0);
    }
};