class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
    map<int,int>m;
    for(auto it:nums){
        m[it]=1;
    }    
        int maxi=1;
    for(auto it:m){
        if(m[it.first-1]){
          m[it.first]=m[it.first-1]+1;
            maxi=max(maxi,m[it.first]);
        }
    }

    return maxi;
    }
};