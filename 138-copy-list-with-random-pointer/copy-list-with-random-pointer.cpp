/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head )return head;
        Node* temp=head;
        // built clone connections
        while(temp!=NULL){
            Node* nxtele=temp->next;
            Node* newnode=new Node(temp->val);
            newnode->next=nxtele;
             temp->next=newnode;
            temp=nxtele;
        }
        // connect random of clone list
        temp=head;
         while(temp!=NULL){
           
            if( temp->random!=NULL)temp->next->random=temp->random->next;
            temp = temp->next->next;
        }
         // break previous connections to separate out clone list
          temp=head;
        Node* dummy=new Node(-1);
        Node* copy=dummy;
         while(temp!=NULL){
            copy->next=temp->next;
           temp->next=temp->next->next;
              temp=temp->next;
              copy=copy->next;
        }
            return dummy->next;
    }
};