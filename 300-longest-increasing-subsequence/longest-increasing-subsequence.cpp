class Solution {
public:
    int f(int idx,vector<int>& nums,int n,int prev,vector<vector<int>>&dp,int mini){
        if(idx>=n)return 0;

        if(prev!=-1e5 && dp[idx][prev-mini]!=-1)return dp[idx][prev-mini];
        // take
        int take=0;
        if(nums[idx]>prev)take=1+f(idx+1,nums,n,nums[idx],dp,mini);

        // leave
        int leave=f(idx+1,nums,n,prev,dp,mini);

        if(prev==-1e5)return max(take,leave);
      else  return  dp[idx][prev-mini]=max(take,leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<vector<int>>dp(n,vector<int>(maxi-mini+1,-1));
        return f(0,nums,n,-1e5,dp,mini);
    }
};