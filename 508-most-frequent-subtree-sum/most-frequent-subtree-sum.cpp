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
    int f(TreeNode* root,map<int,int>&m){
        if(!root)return 0;
        int left=f(root->left,m);
        int right=f(root->right,m);

        int sum=left+right+root->val;
        m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        f(root,m);
       int maxFreq = 0;
        for (auto& [key, val] : m) {
            maxFreq = max(maxFreq, val);
        }

        vector<int> v;
        for (auto& [key, val] : m) {
            if (val == maxFreq) v.push_back(key);
        }

        return v;
    }
};