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
int f(ListNode*head){
    int ct=0;
    while(head!=NULL){
        ct++;
        head=head->next;
    }
    return ct;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL || k==0)return head;
        int n=f(head);
        int len=k%n;
        if(len==0)return head;
        ListNode*temp=head;
        int go=n-len;
        ListNode* store=NULL;
        while(temp->next!=NULL){
            if(go==1){
                store=temp;
            }
            go--;
            temp=temp->next;
        }
        temp->next=head;
        head=store->next;
        store->next=NULL;
        return head;
    }
};