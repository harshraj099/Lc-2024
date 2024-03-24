class Solution {
public:
    int solve(int idx,int target,vector<int>& nums, vector<vector<int>>&dp){
        if(idx==0){
            if(nums[0]==0 && target==0)return 2;
            if(target==0 || target==nums[0])return 1;
            return 0;
        }
        if(dp[idx][target]!=-1)return dp[idx][target];
        // take
        int take=0;
        if(nums[idx]<=target)take=solve(idx-1,target-nums[idx],nums,dp);

        // not take
        int not_take=solve(idx-1,target,nums,dp);

        return dp[idx][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //s1-s2=target
        // totsum-s1=s2
        //totsum-2s2=target
        // s2=(totsum-target)/2
        int totsum=0;
        for(auto it:nums)totsum+=it;
       int  s2=(totsum-target)/2;
       int n=nums.size();
               if(target>totsum || (double(totsum-target)/2)-s2!=0)return 0;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
       return solve(n-1,s2,nums,dp);
    }
};