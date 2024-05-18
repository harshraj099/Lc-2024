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
     int f(TreeNode* root,int &ct){
        if(!root)return 0;

        int left=f(root->left,ct);
        int right=f(root->right,ct);

        ct+=abs(root->val+left+right-1);
        return root->val+left+right-1;
     } 
    int distributeCoins(TreeNode* root) {
        int ct=0;
         f(root,ct);
         return ct;
    }
};