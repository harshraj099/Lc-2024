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
    void f(TreeNode* root,string s,vector<string>&vec){    //string &s
        if(root->left==NULL && root->right==NULL){         // agar & hata rahe ho to no need 
             s+=to_string(root->val);                      // need of pop_back()
             //  cout<<s<<" ";
            vec.push_back(s);
        // s.pop_back();
        return;}
        s+=to_string(root->val);
       if(root->left!=NULL)f(root->left,s,vec);
    if(root->right!=NULL) f(root->right,s,vec);
        // s.pop_back();
        return;
        }
    int sumNumbers(TreeNode* root) {
        string s="";
        vector<string>vec;
        f(root,s,vec);
        int sum=0;
        for(auto it:vec){
            sum+=stoi(it);
        }
        return sum;
    }
};