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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int ct=0;
        ListNode* test=head,*left,*right;
        while(ct<r){
            ct++;
            if(ct==l)left=test;
            if(ct==r)right=test;
            test=test->next;
        }
        ListNode* ptr1=left,*ptr2=right,*dummy=head;
        ListNode* rt=right->next;
        while(left!=right){
            ListNode* temp=left->next;
            left->next=rt;
            rt=left;
            left=temp;
        }
        left->next=rt;
        rt=left;
        
        if(ptr1==head){
           return left;
        }
        else {
            while(dummy->next!=ptr1){
                dummy=dummy->next;
            }
            dummy->next=left;
            return head;
        }
        
    }
};