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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // map<ListNode*,int>m;
        // while(headA!=nullptr){
        //     m[headA]=1;
        //     headA=headA->next;
        // }
        //  while(headB!=nullptr){
        //     if(m.find(headB)!=m.end())return headB;
        //     headB=headB->next;
        // }

        // return NULL;

        // or mind blowing method
        ListNode *t1=headA,*t2=headB;
        while(t1!=t2){
          t1=t1->next;
            t2=t2->next;
            if(t1==NULL && t2==NULL)return NULL;
            if(t1==NULL)t1=headB;
            if(t2==NULL)t2=headA;
        }
        return t1;
    }
};