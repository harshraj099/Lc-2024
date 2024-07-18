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
  vector<int> solve(TreeNode* root, int k,int &ct){
        if(!root)return {10000};
        if(!root->left && !root->right)return {1};
        auto left=solve(root->left,k,ct);
        auto right=solve(root->right,k,ct);
        
        for(auto i:left){
            for(auto j:right){
                if(i+j<=k)ct++;
            }
        }
       vector<int>v;

       for(auto x:left)v.push_back(x+1);
       for(auto y:right)v.push_back(y+1);

        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        int ct=0;
       solve(root,distance,ct); 

       return ct;
    }
};