class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // if(k==0)return 0;
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
            // m.insert({nums[i],{i}});
        }
        for(auto it:m){
            vector<int>v=it.second;
            map<int,vector<int>>idx;
            for(int i=1;i<v.size();i++){
                int ab=v[i]-v[i-1];
                if(ab<=k)return true;
                idx[i].push_back(ab);
                for(auto ind:idx[i-1]){
                    if(ab+ind<=k)return true;
                idx[i].push_back(ab+ind);
                }
            }
        }
        return 0;
    }
};