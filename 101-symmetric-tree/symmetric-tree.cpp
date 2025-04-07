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
    bool f(TreeNode* l,TreeNode* r){
        if(!l && !r)return true;
        if(!l && r || l && !r)return false;
        if(l->val!=r->val)return false;

        if(!f(l->left,r->right))return false;
        if(!f(l->right,r->left))return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {

        return f(root->left,root->right);
    }
};