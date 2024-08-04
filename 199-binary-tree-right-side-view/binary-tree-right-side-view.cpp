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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
          vector<int> ans;
    //    map<int,int>m;  //nade,horizontal level
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});
      while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
             TreeNode* node=q.front().first;
          int level=q.front().second;
          q.pop();
          if(i==n-1)ans.push_back(node->val);
        // cout<<i<<"->"<<" ";
        //   if(m.find(level)==m.end())m[level]=node->data;
          if(node->left)q.push({node->left,level+1});
          if(node->right)q.push({node->right,level+1});
        }
        // cout<<endl;
            }
        // for(auto it:m){
        //     ans.push_back(it.second);
        // }
        return ans;
    }
};