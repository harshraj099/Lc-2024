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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==1)return lists[0];
        ListNode* head = NULL;

        for(int i=0;i<n;i++){
            ListNode *dummy=new ListNode(-1);                
            ListNode* temp = dummy;          
            ListNode* ptr = lists[i];
            while(head && ptr){
                if(ptr->val<head->val){
                    temp->next=ptr;
                    ptr=ptr->next;
                }
                else {
                   temp->next=head;
                   head=head->next;
                }
                temp=temp->next;
            }
            temp->next=head?head:ptr;
            head=dummy->next;
        }

        return head;
    }
};