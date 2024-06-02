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
        ListNode* f(ListNode* head,int k){
            while(head!=NULL){
                if(k==1)return head;
                k--;
                head=head->next;
            }
            return NULL;
        }
         ListNode* reverse(ListNode* head) {
            ListNode* temp=head;
    ListNode* prev=NULL,*dummy=head;
    while(head!=NULL){
        dummy=head;
         head=head->next;
        dummy->next=prev;
      prev=dummy;
    }  
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
        ListNode* kth=f(temp,k);
            if(kth==NULL){
                if(prevlast)prevlast->next=temp;
                break;
            }
            ListNode* nextnode=kth->next;
            kth->next=NULL;

            reverse(temp);
            if(temp==head){
                head=kth;
            }
            else {
                prevlast->next=kth;
            }
            prevlast=temp;
            temp=nextnode;   
        }

    return head;
    }
};