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
 
    TreeNode* first;
    TreeNode* last;
    TreeNode* middle;
    void solve(TreeNode* root,TreeNode* &prev){
        if(root==NULL)return;
        solve(root->left,prev);
        if((root->val<prev->val)){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        solve(root->right,prev);
    }
    void recoverTree(TreeNode* root) {
         first = middle = last = NULL;
           TreeNode* prev=new TreeNode(INT_MIN);   
        solve(root,prev);
        // there could be at most 2 places where violation
        // could exist , if violation=2 swap first and last else 
        // first and middle 
        if(first && last)swap(first->val,last->val);
        else swap(first->val,middle->val);
    }
};