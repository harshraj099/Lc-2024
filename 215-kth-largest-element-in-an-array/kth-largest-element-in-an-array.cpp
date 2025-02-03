class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(!pq.empty() && k>1){
            pq.pop();
            k--;
        }
        if(k>1)return 0;
      if(!pq.empty()) return pq.top();
      return 0;
    }
};