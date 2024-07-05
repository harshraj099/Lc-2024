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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>store;
        int prev=head->val;
        ListNode* temp=head->next;
        int ct=2;
        while(temp->next){
            if(temp->val>prev && temp->val>temp->next->val){
                store.push_back(ct);
            }
          else if(temp->val<prev && temp->val<temp->next->val){
                store.push_back(ct);
            }
            ct++;
            prev=temp->val;
            temp=temp->next;
        }
        if(store.size()<2)return {-1,-1};
        sort(store.begin(),store.end());
        int mini=1e8;

        for(int i=0;i<store.size()-1;i++){
            mini=min(mini,store[i+1]-store[i]);
        }
        return {mini,store[store.size()-1]-store[0]};
    }
};