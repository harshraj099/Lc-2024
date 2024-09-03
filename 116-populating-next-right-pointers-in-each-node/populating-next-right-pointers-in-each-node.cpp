/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void f(Node* root,map<int,Node*>&m,int level){
        if(!root)return;

        f(root->right,m,level+1);
        if(m.find(level)!=m.end()){
            root->next=m[level];
        // cout<<level<<"->"<<root->val<<endl;
        }
        else  root->next=NULL;
        m[level]=root;
        // cout<<level<<"->"<<root->val<<endl;
         f(root->left,m,level+1);
    }
    Node* connect(Node* root) {
        queue<pair<int,int>>q;
        map<int,Node*>m;
        f(root,m,1);
        
        return root;
    }
};