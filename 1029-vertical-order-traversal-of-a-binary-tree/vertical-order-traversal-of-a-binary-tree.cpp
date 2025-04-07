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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int,map<int,vector<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q; 
        q.push({root,{0,0}});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int y=q.front().second.first;
                int x=q.front().second.second;
                m[y][x].push_back(node->val);
                q.pop();
                if(node->left)q.push({node->left,{y-1,x+1}});
                if(node->right)q.push({node->right,{y+1,x+1}});
            }
        }
        for(auto [y,mp]:m){
            vector<int>temp;
            for(auto [row,arr]:mp){
                sort(arr.begin(),arr.end());
                for(auto a:arr){
                  temp.push_back(a);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};