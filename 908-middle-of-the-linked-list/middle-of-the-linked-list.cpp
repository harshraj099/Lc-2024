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
    // int length(ListNode* head,int &len){
    //     if(head==NULL)return len;
    //     len++;
    //     length(head->next,len);
    //     return len;
    //         }

    //         ListNode* f(ListNode* head,int l){
    //             if(l==1) return head;
    //             l--;
    //            return f(head->next,l);
    //             return head;
    //         }
    ListNode* middleNode(ListNode* head) {
    //     int len=0;
    //    int l= length(head,len);

    //    if(l%2==0){
    //        l=l/2+1;
    //        return f(head,l);
    //    }
    //    else{
    //        l=(l+1)/2;
    //        return f(head,l);
    //    }

    //  method 2
    // tortoise method
    ListNode* slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }
};