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
        vector<int>arr;
        // odd
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            // cout<<temp->val<<" ";
           if(temp->next!=NULL)temp=temp->next->next;
           else temp=temp->next;
        }
        if(temp)arr.push_back(temp->val);
        // cout<<endl;
        // even
        temp=head->next;
         while(temp!=NULL){
            arr.push_back(temp->val);
            // cout<<temp->val<<" ";
           if(temp->next!=NULL)temp=temp->next->next;
           else temp=temp->next;
        }
        if(temp)arr.push_back(temp->val);
        // cout<<endl;
        // for(auto it:arr)cout<<it<<" ";
        temp=head;
            int i=0;
            while(temp!=NULL){
            temp->val=arr[i];
            temp=temp->next;
            i++;
            }
    
    return head;
    }
};