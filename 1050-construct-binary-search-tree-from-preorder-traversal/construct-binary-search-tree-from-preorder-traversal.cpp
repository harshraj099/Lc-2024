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
    TreeNode* f(vector<int>& preorder,int low,int high){
            if(low>high)return NULL;
        TreeNode* root=new TreeNode(preorder[low]);
        int idx=low+1;
        while(idx<=high && preorder[low]>preorder[idx]){
            idx++;
        }
       root->left= f(preorder,low+1,idx-1);
       root->right= f(preorder,idx,high);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
       return f(preorder,0,n-1);
    }
};