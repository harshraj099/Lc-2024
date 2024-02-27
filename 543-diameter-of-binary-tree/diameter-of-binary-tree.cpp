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
int k=0;
int diameter1(TreeNode* root)
        {if(root==NULL)return 0;
        int left=diameter1(root->left);
        int right=diameter1(root->right);
        k=max(k,(left+right));
        return 1+max(left,right);}
      
    int diameterOfBinaryTree(TreeNode* root) {
      
          diameter1(root);
        return k;
    }
};