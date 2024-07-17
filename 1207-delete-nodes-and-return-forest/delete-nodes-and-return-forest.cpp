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
    void solve(TreeNode* root,set<int>s, vector<TreeNode*>&ans){
        if(!root)return;

        if(s.find(root->val)!=s.end()){
           if(root->left) solve(root->left,s,ans);
           if(root->right) solve(root->right,s,ans);
        }
        else {
            ans.push_back(root);
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                if(s.find(node->left->val)!=s.end()){
                    solve(node->left,s,ans);
                    node->left=NULL;
                }
                else q.push(node->left);
                }
                 if(node->right){
                if(s.find(node->right->val)!=s.end()){
                    solve(node->right,s,ans);
                    node->right=NULL;
                }
                else q.push(node->right);
                }
            }
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>s;
        for(auto it:to_delete)s.insert(it);
        vector<TreeNode*> ans;

        solve(root,s,ans);
        return ans;

    }
};