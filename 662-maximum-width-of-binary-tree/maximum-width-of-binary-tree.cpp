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
    int widthOfBinaryTree(TreeNode* root) {
         if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long ans=-1e9;
        while(!q.empty()){
            int size=q.size();
            long long leftMost = 0, rightMost = 0;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front().first;
                 long long level=q.front().second;
                if (i == 0) leftMost = level;
                if (i == size - 1) rightMost = level;
                q.pop();
                if(node->left!=NULL)q.push({node->left,(long long)2*level+1});
                if(node->right!=NULL)q.push({node->right,(long long)2*level+2});
            }
           ans = max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};