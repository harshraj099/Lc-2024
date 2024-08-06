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
    void solve(TreeNode* root,TreeNode* &a,TreeNode* &b,TreeNode* &mid,TreeNode* &prev){
        if(!root)return;
        // inorder
        solve(root->left,a,b,mid,prev);
        if(prev && root->val<prev->val){
            if(!a){
                a=prev;
                mid=root;
            }
            else b=root;
        }
         prev=root;
        solve(root->right,a,b,mid,prev);
    }
    void recoverTree(TreeNode* root) {
      TreeNode* a=NULL,*b=NULL,*mid=NULL;  
      TreeNode* prev=NULL;
      solve(root,a,b,mid,prev);
      if(a && b)swap(a->val,b->val);  // 2 points me inorder traversal different hai
      else if(a && mid )swap(a->val,mid->val);   // 1 hi point me inorder different hai
    }
};