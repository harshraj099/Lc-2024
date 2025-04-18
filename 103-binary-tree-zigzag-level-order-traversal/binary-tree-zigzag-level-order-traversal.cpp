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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        int num=0;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
             TreeNode* node=q.front();
             q.pop();
            v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
        }
        if(num%2==0) ans.push_back(v);
        else {
        reverse(v.begin(),v.end());
        ans.push_back(v);
        }
        num+=1;
        }
        return ans;
    }
};