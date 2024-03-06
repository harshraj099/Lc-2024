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
    bool f(ListNode *head,map<ListNode*,int>&m){
        if(head==NULL)return true;
      
        if(m.find(head)!=m.end())return false;
          m[head]++;
       if(!f(head->next,m)) return false;
       return true;
    }
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>m;
       return  !f(head,m);
     
    }
};