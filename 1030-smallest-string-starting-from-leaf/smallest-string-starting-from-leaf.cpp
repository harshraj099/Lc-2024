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
string ans="";
void f(TreeNode* root,string s)
{
    if(!root)return;
    if(root->left==NULL && root->right==NULL){
    s+=97+root->val;
        string temp="";
        for(int i=s.size()-1;i>=0;i--)temp+=s[i];
        if(ans.size()==0)ans=temp;
        else {
            if(temp<ans)ans=temp;
        }
        return;
    }
    s+=97+root->val;
    f(root->left,s);
    f(root->right,s);
    return ;
    // s.pop_back();
}
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        f(root,s);
        return ans;
    }
};