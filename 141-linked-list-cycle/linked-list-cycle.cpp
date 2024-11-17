/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return 0;
        if(!head->next)return 0;

        ListNode *slow=head,*fast=head;
        while(fast){
            slow=slow->next;
          if(fast->next)fast=fast->next->next;
          else break;
            if(slow==fast)return 1;
        }
        return 0;
    }
};