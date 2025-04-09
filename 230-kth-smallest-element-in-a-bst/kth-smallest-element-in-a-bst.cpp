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
    void f(TreeNode* root, int k,int &store,int &ct){
        if(!root)return ;
  
          f(root->left,k,store,ct);
          ct++;
           if(ct==k){
           store=min(store,root->val);
        }
          f(root->right,k,store,ct);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int store=1e9;
        if(!root)return 0;
        int ct=0;
        f(root,k,store,ct);

        return store;
    }
};