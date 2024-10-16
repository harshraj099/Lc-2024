class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()-1)return 0;

        if(dp[i]!=-1)return dp[i];
        int mini=1e9;
        for(int jump=1;jump<=nums[i];jump++){
            mini=min(mini,1+f(i+jump,nums,dp));
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
    }
};