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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ct=1;
        if(!head)return head;
        if(!head->next)return head->next;
         ListNode* slow=head,*fast=head;

         while(fast && fast->next){
            ct++;
            slow=slow->next;
            fast=fast->next->next;
         }
         int m;
         if(fast)m=2*ct-1;
         else m=(ct-1)*2;

         m=m-n;
        slow=head;
        if(m==0)return head->next;
         while(--m){
            slow=slow->next;
         }
         slow->next=slow->next->next;

         return head;
    }
};