class Solution {
public:
      bool f(int idx,vector<int>&arr, int target, vector<vector<int>>&dp){
        if(target==0)return dp[idx][target]=true;
        if(idx==0)return dp[idx][target]=arr[idx]==target;
       
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool not_pick=f(idx-1,arr,target,dp);
        bool pick=false;
        if(arr[idx]<=target){
           pick=f(idx-1,arr,target-arr[idx],dp);
        }
            return dp[idx][target]=pick|not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2==1)return 0;
        sum=sum/2;
         vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return f(nums.size()-1,nums,sum,dp);
    }
};