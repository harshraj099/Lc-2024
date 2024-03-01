class Solution {
public:
    int f(int idx,vector<int>& coins, int k,vector<vector<int>>&dp){
        if(idx==0){
            if(k%coins[idx]==0)return dp[idx][k]=k/coins[idx];
            else return 1e9;
        }
        if(dp[idx][k]!=-1)return dp[idx][k];
        int not_take=0+f(idx-1,coins,k,dp);
        int take=INT_MAX;
        if(coins[idx]<=k)take=1+f(idx,coins,k-coins[idx],dp);

        return dp[idx][k]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int ans= f(coins.size()-1,coins,amount,dp);
       if(ans==1e9)return -1;
       return ans;
    }
};