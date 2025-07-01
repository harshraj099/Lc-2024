class Node {
    public:
    Node * links[2];
    bool flag=false;

    bool iskey(int bit){
        return links[bit]!=NULL;
    }

    void join(int bit, Node * node){
        links[bit]=node;
    }

    Node * get(int bit){
        return links[bit];
    }
};

class Trie{
    public:
    Node *root=new Node();
    void create(int num){
        Node * node=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->iskey(bit)){
                node->join(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int returnmax(int num){
        Node* node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
           int bit = (num>>i)&1;
            if(node->iskey(1-bit)){  // opposite bit wanted for maximum
               maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
          else  node=node->get(bit);   // if not 1 then 0 or vice versa
        }
        return maxnum;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums){
            trie.create(it);
        }
        int maxi=0;
        for(auto it:nums){
            maxi=max(maxi,trie.returnmax(it));
        }
        return maxi;
    }
};