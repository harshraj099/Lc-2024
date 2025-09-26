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
    bool solve(TreeNode* p, TreeNode* q){
        if(!p && q || p && !q)return false;
        if(!p && !q)return true;

        if(p->val!=q->val)return false;
        if(!solve(p->left,q->left))return false;
        if(!solve(p->right,q->right))return false;
        return true;
    } 
    bool f(TreeNode* root, TreeNode* subRoot){
        if(!root)return false;

        if(root->val==subRoot->val){
            if(solve(root,subRoot))return true;
        }
        if(f(root->left,subRoot))return true;
        if(f(root->right,subRoot))return true;

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root,subRoot);
    }
};