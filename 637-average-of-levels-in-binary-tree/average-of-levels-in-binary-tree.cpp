/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
          if(!root)return {};

        vector<TreeNode*>vec[1000];
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});

        while(!q.empty()){
            int level=q.front().first;
            TreeNode* TreeNode=q.front().second;
            vec[level].push_back(TreeNode);
            q.pop();
            if(TreeNode->left)q.push({level+1,TreeNode->left});
            if(TreeNode->right)q.push({level+1,TreeNode->right});
        }
        
        vector<double>ans;
        for(auto it:vec){
            if(it.size()==0)break;
            long long sum=0;
            for(auto i:it){
                sum+=i->val;
            }
          ans.push_back((double)sum/it.size()) ;
        }

        return ans;
    }
};