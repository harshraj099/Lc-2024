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
    bool f(TreeNode* root,long long mini,long long maxi){
        if(!root)return 1;
            if(root->val <= mini || root->val>=maxi)return false;

            if(!f(root->left,mini,root->val))return false;
            if(!f(root->right,root->val,maxi))return false;

            return true;
    }
    bool isValidBST(TreeNode* root) {
       return f(root,-1e12,1e12);  
    //    range [min,max]
    }
};