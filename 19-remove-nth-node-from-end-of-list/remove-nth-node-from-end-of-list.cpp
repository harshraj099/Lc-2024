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
        int count=0;
        ct(head,count);
        cout<<count;
        if(count==1)return NULL;
        int r=count-n+1;
        if(r==1){
            head=head->next;
            return head; 
        }
        f(1,head,r);
        return head;
    }
};