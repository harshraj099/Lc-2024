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
    ListNode* reverseList(ListNode* head){
        ListNode *cur=head,*prev=NULL;

        while(cur){
            ListNode* temp=cur->next;
          cur->next=prev;
          prev=cur;
          cur=temp;
        }
        // cout<<prev->val;

        return prev;
    }
    bool isPalindrome(ListNode* head) {
         ListNode *fast=head,*slow=head;
     while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }

        ListNode *cur;
       if(fast) cur=slow->next;
       else cur=slow;

     fast=reverseList(cur);
        
        while(head!=slow && fast){
            // cout<<head->val<<" "<<fast->val<<endl;
            if(head->val==fast->val){
                head=head->next;
                fast=fast->next;
            // cout<<head->val<<" "<<fast->val<<endl;
            }
            else return 0;
        }
        return 1;
    }
};