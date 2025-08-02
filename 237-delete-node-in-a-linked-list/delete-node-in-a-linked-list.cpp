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
    void deleteNode(ListNode* node) {

        ListNode* temp=node->next;
        if(!temp){node=NULL;
        return;}
        node->val=temp->val;
        node->next=temp->next;

    //    ListNode* temp=node->next;
    //    while(temp){
    //     node->val=temp->val;
    //     node=temp;
    //     temp=temp->next;
    //    }
    //    node=NULL;
    }
};