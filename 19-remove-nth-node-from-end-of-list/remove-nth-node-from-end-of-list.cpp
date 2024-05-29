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
     void f(int ct,ListNode* head, int n){
         if(ct==n-1){
             ListNode* temp=head->next;
             head->next=temp->next;
             return;
         }
        return f(ct+1,head->next,n);
     }
     void ct(ListNode* head, int &cnt){
         if(head==NULL)return;
         cnt++;
        return ct(head->next,cnt);
     }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(n==1){
        //     head=head->next;
        //     return head;
        // }
        // int count=0;
        // ct(head,count);
        // cout<<count;
        // if(count==1)return NULL;
        // int r=count-n+1;
        // if(r==1){
        //     head=head->next;
        //     return head; 
        // }
        // f(1,head,r);
        // return head;

        if(head->next==NULL && n==1)return NULL;
         ListNode* fast=head,*slow=head;
           int ct=1;
            while(ct<=n){
               ct++;
             fast=fast->next;
           }
           if(!fast)return head->next;
           while(fast->next!=NULL){
               fast=fast->next;
               slow=slow->next;
           }
        // delete slow->next;
    //    if(slow->next!=NULL)slow->next=slow->next->next;
    // or
      slow->next=slow->next->next;

          return head;
     
    }
};