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
        // 1st parnet store kero each node ka
      map<TreeNode*,TreeNode*>par;
      queue<pair<TreeNode*,TreeNode*>>q;
      q.push({root,root});
      int n=0;
    while(!q.empty()){
        n++;
        TreeNode* node=q.front().first;
        TreeNode* parent=q.front().second;
        q.pop();
        par[node]=parent;
        if(node->left){
            q.push({node->left,node});
        }
         if(node->right){
            q.push({node->right,node});
        }
    }
    // ab traversal kerke ans store kero
    vector<int>ans;
    vector<int>vis(n+1,0);
    queue<pair<TreeNode*,int>>pq; // node,dist
    pq.push({target,0});
    vis[target->val]=1;
    while(!pq.empty()){
        TreeNode* node=pq.front().first;
        int dist=pq.front().second;
        vis[node->val]=1;
        pq.pop();
        if(dist==k)ans.push_back(node->val);
        if(node->left && !vis[node->left->val])pq.push({node->left,dist+1});
        if(node->right && !vis[node->right->val])pq.push({node->right,dist+1});
        if(!vis[par[node]->val])pq.push({par[node],dist+1});
    }
    return ans;
    }
};