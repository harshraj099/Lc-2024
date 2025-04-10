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
    void f(TreeNode* root,TreeNode* &prev,TreeNode* &mid,TreeNode* &num1,TreeNode* &num2){
        if(!root)return ;
        // inorder
            f(root->left,prev,mid,num1,num2);
            
            if(prev && root->val<prev->val){
                if(!num1){
                    num1=prev;
                    mid=root;
                }
                else num2=root;
            }

                prev=root;
            f(root->right,prev,mid,num1,num2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* mid=NULL;
        TreeNode* num1=NULL;
        TreeNode* num2=NULL;

         f(root,prev,mid,num1,num2);
        
        if(!num2)swap(num1->val,mid->val);  
        else swap(num1->val,num2->val); 
         
    }
};