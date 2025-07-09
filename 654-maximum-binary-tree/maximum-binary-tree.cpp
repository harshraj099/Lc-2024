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
    TreeNode* f(vector<int>& nums){
        if(nums.size()==0)return NULL;
        int ind=max_element(nums.begin(),nums.end())-nums.begin();
        TreeNode* node=new TreeNode(nums[ind]);
        vector<int>left(nums.begin(),nums.begin()+ind);
        node->left=f(left);
        vector<int>right(nums.begin()+ind+1,nums.begin()+nums.size());
        node->right=f(right);

        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return f(nums);
    }
};