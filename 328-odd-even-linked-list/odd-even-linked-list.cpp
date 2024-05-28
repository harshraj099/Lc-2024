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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next==NULL)return head;
    //     vector<int>arr;
    //     // odd
    //     ListNode* temp=head;
    //     while(temp!=NULL){
    //         arr.push_back(temp->val);
    //        if(temp->next!=NULL)temp=temp->next->next;
    //        else temp=temp->next;
    //     }
    //     if(temp)arr.push_back(temp->val);
    //     // even
    //     temp=head->next;
    //      while(temp!=NULL){
    //         arr.push_back(temp->val);
    //        if(temp->next!=NULL)temp=temp->next->next;
    //        else temp=temp->next;
    //     }
    //     if(temp)arr.push_back(temp->val);
    //     temp=head;
    //         int i=0;
    //         while(temp!=NULL){
    //         temp->val=arr[i];
    //         temp=temp->next;
    //         i++;
    //         }
    
    // return head;

    // method 2
    ListNode   *odd=head,*even=head->next,*dummy=even;
        
        while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
         even->next=even->next->next;
         odd=odd->next;
         even=even->next;
      
        }
        odd->next=dummy;

        return head;
    }
};