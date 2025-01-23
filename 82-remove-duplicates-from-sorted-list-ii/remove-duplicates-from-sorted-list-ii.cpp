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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(head){
            if(!head->next){
                temp->next=head;
                head=head->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else if (head->val!=head->next->val){
                temp->next=head;
                head=head->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else {
               while(head->next && head->val==head->next->val){
                head=head->next;
               }
               head=head->next;
            }
        }

        return dummy->next;
    }
};