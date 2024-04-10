class Solution {
public:
    bool f(int idx,vector<int>& nums,int end,vector<int>&dp){
        if(idx>=end)return true;
        // if(nums[idx]==0)return false;
        if(dp[idx]!=-1)return dp[idx];
        for(int sum=1;sum<=nums[idx];sum++){
            if(f(idx+sum,nums,end,dp))return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(0,nums,n-1,dp);
    }
};