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
    queue<pair<TreeNode*,long long>>q;
    q.push({root,0});
    long long maxwidth=0;
    while(!q.empty()){
        int size=q.size();
        int first=0,last=0;
        for(int i=0;i<size;i++){
            int idx=q.front().second;
            if(i==0)first=idx;
            if(i==size-1)last=idx;
            TreeNode* node=q.front().first;
            q.pop();
            if(node->left)q.push({node->left,(long long)2*idx+1});
            if(node->right)q.push({node->right,(long long)2*idx+2});
        }
        maxwidth=max(maxwidth,(long long)last-first+1);
    }
    return maxwidth;
    }
};