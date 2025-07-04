class Solution {
public:
    int  f(int i,int n,vector<int>& nums,int prev,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }

        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        // take 
        int take=0;
        if(prev==-1 || nums[i]>nums[prev])take=1+f(i+1,n,nums,i,dp);

        // leave
        int leave=f(i+1,n,nums,prev,dp);

        return dp[i][prev+1] =max(take,leave);
    }
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
      return f(0,n,nums,-1,dp);  
    }
};