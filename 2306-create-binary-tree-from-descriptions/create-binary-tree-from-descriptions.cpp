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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int>st;
        int top;
        map<int,vector<pair<int,int>>>m;
         for(auto it: descriptions){
            int parent=it[0];
            int child=it[1];
            int side=it[2];
            m[parent].push_back({child,side});
            st.insert(child);
            // if(st.find(parent)==st.end())top=parent;
        }

        for(auto it:m)
        {
            if(st.find(it.first)==st.end()){
                top=it.first;
                break;
            }
        }

        TreeNode* root=new TreeNode(top);
        TreeNode* dummy=root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
             TreeNode* node=q.front();
             q.pop();
           for(auto it:m[node->val]){
            // cout<<it.first<<" "; 
            TreeNode* temp=new TreeNode(it.first);
             if(it.second==1){
            node->left=temp;
            q.push(temp);
            }
            else {
            node->right=temp;
            q.push(temp);
            }
           }
        }

        return dummy;
    }
};