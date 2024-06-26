class Solution {
public:
    int f(int n,int temp,int check,vector<int>&dp){
        if(n==0)return 1;
        if(dp[temp]!=-1)return dp[temp];
        int take=0;
        if((temp-n+1)!=check)take=(temp-n+1)*f(n-1,n-1,check,dp);

        int not_take=f(n-1,temp,check,dp);
        return dp[temp]=max(take,not_take);
    }
    int integerBreak(int n) {
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<int>dp(n+1,-1);
        return f(n,n,n,dp);
    }
};