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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next)return head;
        if(k==0)return head;
       ListNode* slow=head,*fast=head,*last;
       int ct=1;
       while (fast && fast->next){
        ct++;
            if(!fast->next->next)last=fast->next;
            slow=slow->next;
            fast=fast->next->next;
       }
       int n=0;
    //    cout<<ct;
       if(fast){n=2*ct-1;
       last=fast;}
       else n=(ct-1)*2;
    //    cout<<n;
       k=k%n;
       if(k==0)return head;
       ListNode* temp=head;
       k=n-k;
       while(--k){
        temp=temp->next;
       }
    ListNode* dummy=temp->next;
       temp->next=NULL;
        last->next=head;

        return dummy;
    }
};