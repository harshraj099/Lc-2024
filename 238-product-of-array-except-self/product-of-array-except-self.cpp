class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ct=count(nums.begin(),nums.end(),0);
        if(ct>1){
            vector<int>v(nums.size(),0);
            return v;
        }
        if(ct==0)
        {        int n=1;
            for(auto it:nums)n=n*it;
        vector<int>v;
        for(auto it:nums){
            v.push_back(n/it);
        }
        return v;
        }
        else{
             int n=1;
            for(auto it:nums)if(it!=0)n=n*it;
        vector<int>v;
        for(auto it:nums){
           if(it==0) v.push_back(n);
           else v.push_back(0);
        }
        return v;
        }
    }
};