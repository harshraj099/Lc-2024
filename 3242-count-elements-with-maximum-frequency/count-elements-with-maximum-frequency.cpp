class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums)m[it]++;

        int update=1;
        int ct=0;
        for(auto it:m){
            if(it.second==update)ct+=it.second;
            if(it.second>update){
                update=it.second;
                ct=it.second;
            }
        }
        return ct;
    }
};