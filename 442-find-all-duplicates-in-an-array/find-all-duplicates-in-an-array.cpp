class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        vector<int>v;
        for(auto it:m){
            if(it.second==2)v.push_back(it.first);
        }
        return v;
        
    }
};