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
      ListNode *merge(ListNode* l1,ListNode* l2){
         
         ListNode* dummy=new ListNode(-1);
         ListNode* newhead=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val>l2->val){
                dummy->next=l2;
                l2=l2->next;
            }
            else {dummy->next=l1;
                l1=l1->next;
            }
            dummy=dummy->next;
        }
        if(l1)dummy->next=l1;
        else dummy->next=l2;
        
        return newhead->next;
    }
    ListNode* findmid(ListNode* head){
        ListNode* slow=head,*fast=head;
        ListNode* ret=NULL;
        while(fast!=NULL && fast->next!=NULL){
            ret=slow;         // get 1st middle
            slow=slow->next;
            fast=fast->next->next;
        }
        return ret;
    }
     ListNode* mergesort( ListNode* head){
        if(!head || head->next==NULL)return head;

        ListNode* middle=findmid(head);
        ListNode* midright=middle->next;
        middle->next=NULL;
         ListNode* left=mergesort(head);
         ListNode* right=mergesort(midright);

         return merge(left,right);
     }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};