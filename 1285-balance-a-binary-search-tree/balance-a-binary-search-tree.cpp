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
    void f(TreeNode* root,vector<int>&store){
        if(!root)return;
        f(root->left,store);
        store.push_back(root->val);
        f(root->right,store);
    }
    TreeNode* create(vector<int>&store,int l,int r){
        if(l>r)return NULL;
                int m=(l+r)/2;
        TreeNode* root=new TreeNode(store[m]);
        // cout<<n<<endl;
         root->left=create(store,l,m-1);
        root->right=create(store,m+1,r);  
        return root;  
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>store;
        f(root,store);
        int n=store.size();
        // cout<<n;
        return create(store,0,n-1);
    }
};