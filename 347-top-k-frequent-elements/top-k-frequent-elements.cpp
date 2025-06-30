class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto it :nums)m[it]++;
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(auto [num, freq]:m){
          pq.push({freq,num});
        }
        while(!pq.empty() && k>0){
            k--;
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};