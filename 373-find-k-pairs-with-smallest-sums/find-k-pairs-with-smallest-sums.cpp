class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0;i< min(k,(int)nums1.size());i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>>ans;
        while(k-- && !pq.empty()){
            int wt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            vector<int>v={nums1[i],nums2[j]};
            ans.push_back(v);
            pq.pop();
            if(j+1<nums2.size()){
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }

        return ans;
    }
};