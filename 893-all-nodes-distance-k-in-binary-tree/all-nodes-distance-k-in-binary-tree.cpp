/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        map<TreeNode*,TreeNode*>parent;
        // root,parent
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,root}); 
        int n=0;    
        while(!q.empty()){
            TreeNode* node=q.front().first;
            TreeNode* par=q.front().second;
            n++;
            q.pop();
            parent[node]=par;
            if(node->left)q.push({node->left,node});
            if(node->right)q.push({node->right,node});
        }
         vector<int>ans;
         vector<int>vis(n+1,0);
        //  parent use ker k revisit nahi ho jaye node
        queue<pair<TreeNode*,int>>que;
        // node,dist
        que.push({target,0});
        while(!que.empty()){
             TreeNode* node=que.front().first;
            int dist=que.front().second;
            que.pop();
            vis[node->val]=1; 
            if(dist==k)ans.push_back(node->val);

            if(node->left && !vis[node->left->val])que.push({node->left,dist+1});
            if(node->right && !vis[node->right->val])que.push({node->right,dist+1});
            if(parent[node]!=node && !vis[parent[node]->val])que.push({parent[node],dist+1});
        }

        return ans;
    }
};