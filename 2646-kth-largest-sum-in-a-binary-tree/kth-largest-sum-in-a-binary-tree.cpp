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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           long long size=q.size();
           long long sum=0;
           for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
           }
           pq.push(sum);
        }

        if(k>pq.size())return -1;
        long long ans;
        while(!pq.empty()){
            k--;
          if(k==0)  { ans= pq.top();
          break;}
            pq.pop();
        }
        return ans;
    }
};