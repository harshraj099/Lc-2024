/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void f(ListNode *head,int sum,ListNode* root){
        if(!head){
            return;}
        if(head->val!=0)sum+=head->val;
        else{
            root->val=sum;
          if(head->next!=NULL)root=root->next;
          else root->next=NULL;
            sum=0;
        }
        f(head->next,sum,root);
    }
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        f(head->next,sum,head);

        return head;

    }
};