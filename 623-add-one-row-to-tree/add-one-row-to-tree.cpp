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
    void f(TreeNode* root, int val, int depth){
        // if(root==NULL)return;
        // or
        if(!root)return;
        if(depth==1){
               TreeNode* node=new TreeNode(val);
            //    or
            // node->val=val;
            node->left=root->left;
            root->left=node;

               TreeNode* temp=new TreeNode(val);
            // temp->val=val;
            temp->right=root->right;
            root->right=temp;
        }
        else
{        f(root->left,val,depth-1);
        f(root->right,val,depth-1);}     
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            // node->val=val;
            node->left=root;
            // node->right=NULL;
            return node;
        }
     f(root,val,depth-1);
     return root;
    }
};