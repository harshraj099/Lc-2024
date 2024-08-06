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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        TreeNode* temp=root;
        while(true){
          if(!temp->left && temp->val>val){
             TreeNode* node=new TreeNode(val);
             temp->left=node;
             break;
        }
        if(!temp->right && temp->val<val){
             TreeNode* node=new TreeNode(val);
             temp->right=node;
            break;
        }
        if(temp->val<val) temp=temp->right;
        else temp=temp->left;
        }
        
        return root;
    }
};