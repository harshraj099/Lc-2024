class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long no1=0,no2=0;
        long long xr=0;
        for(long long i=0;i<nums.size();i++){
           xr^=nums[i];
        }
        long long real=xr;
        xr=xr&(xr-1);
        real=xr^real;

        for(long long i=0;i<nums.size();i++){
           if((nums[i]&real)!=0)no1=no1^nums[i];
           else no2=no2^nums[i];
        }
           int ans1=no1,ans2=no2; 
        return {ans1,ans2};
    }
};