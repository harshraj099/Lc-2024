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
    Node* connect(Node* root) {
        if(!root)return NULL;

        vector<Node*>vec[100];
        queue<pair<int,Node*>>q;
        q.push({0,root});

        while(!q.empty()){
            int level=q.front().first;
            Node* node=q.front().second;
            vec[level].push_back(node);
            q.pop();
            if(node->left)q.push({level+1,node->left});
            if(node->right)q.push({level+1,node->right});
        }
        
        for(auto it:vec){
            if(it.size()==0)break;
            for(int i=1;i<it.size();i++){
                it[i-1]->next=it[i];
            }
            it[it.size()-1]->next=NULL;
        }

        return root;
    }
};