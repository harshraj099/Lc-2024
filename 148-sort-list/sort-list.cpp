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
    ListNode* merge(ListNode* low,ListNode* high){
        ListNode *dummy=new ListNode(-1),*temp=dummy;
        while(low!=NULL && high!=NULL){
            if(low->val<=high->val){
                temp->next=low;
                low=low->next;
            }
           else{
                temp->next=high;
                high=high->next;
            }
            temp=temp->next;
        }
        if(low!=NULL){
              temp->next=low;
        }
           else{
             temp->next=high;
        }
        
            return dummy->next;
    }
         ListNode* findMiddle( ListNode* head){
             ListNode* slow=head,*fast=head->next;
            
            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }

            return slow;
         }
     ListNode* mergesort( ListNode* head){
        if(!head || !head->next)return head;
        ListNode* middle = findMiddle(head);
    // ListNode* right = middle->next;
     ListNode* midright=middle->next;
    middle->next = NULL;
   ListNode* left= mergesort(head);
  ListNode*  right = mergesort(midright);

       return  merge(left,right);
     }
    ListNode* sortList(ListNode* head) {
      return  mergesort(head);
    }
};