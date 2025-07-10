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
    void f(TreeNode* root,int &mini,int cnt){
        if(!root)return;
        if(!root->left && !root->right){
            mini=min(mini,cnt);
            return;
        }

        f(root->left,mini,cnt+1);
        f(root->right,mini,cnt+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int mini=1e9;
        f(root,mini,1);
        return mini;
    }
};