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
ListNode* rev(ListNode* head,ListNode* tail) {
    tail->next=NULL;
    ListNode* prev=NULL,*dummy=head,*temp=head;
    while(head){
        dummy=head;
         head=head->next;
        dummy->next=prev;
         prev=dummy;
       } 
       return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        if(k==1)return head;
        ListNode* temp=head;
        vector<ListNode*>v;
        while(temp){
           int ct=k-1;
            ListNode* cur=temp;
           while(ct>0 && cur->next){
            cur=cur->next;
            ct--;
           }
        ListNode* dummy=cur->next;
           if(ct==0){
           ListNode*st=rev(temp,cur);
           v.push_back(st);
           }
           else {
            v.push_back(temp);
            break;}
           temp=dummy;
        }
        for(int i=0;i<v.size();i++){
            if(i==0){
                head=v[i];
            }
              while(v[i]->next){
                    v[i]=v[i]->next;
                }
             if(i+1<v.size()) v[i]->next=v[i+1];
             else v[i]->next=NULL;
        }
        return head;
    }
};