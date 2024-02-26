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
void solve(TreeNode* p,vector<int>&vp){
    if(p==NULL){ vp.push_back(-1e5);
        return;}
    vp.push_back(p->val);
    solve(p->left,vp);
    solve(p->right,vp);
}
void solve2(TreeNode* q,vector<int>&vq){
    if(q==NULL){ vq.push_back(-1e5);
        return;}
    vq.push_back(q->val);
    solve2(q->left,vq);
    solve2(q->right,vq);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>vp,vq;
       solve(p,vp); 
       solve2(q,vq); 
       for(auto ele:vp)cout<<ele<<" ";
       cout<<endl;
       for(auto ele:vq)cout<<ele<<" ";

        // for(int i=0;i<vp.size();i++){
        //     if(vp[i]!=vq[i])return false;
        // }
        if(vp!=vq)return false;
        return true;
    }
};