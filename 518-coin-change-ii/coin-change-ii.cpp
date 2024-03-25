class Solution {
public:
        int f(int idx,vector<int>& coins, int k,vector<vector<int>>&dp){
        if(idx==0){
            if(k%coins[idx]==0)return 1;
            else return 0;
        }
        if(dp[idx][k]!=-1)return dp[idx][k];
        int not_take=f(idx-1,coins,k,dp);
        int take=0;
        if(coins[idx]<=k)take=f(idx,coins,k-coins[idx],dp);

        return dp[idx][k]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
              vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int ans= f(coins.size()-1,coins,amount,dp);
    //    if(ans==1e9)return -1;
       return ans;
    }
};