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
    //    vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
    //    int ans= f(coins.size()-1,coins,amount,dp);
    //    if(ans==1e9)return -1;
    //    return ans;

       // tabulation 
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int k=1;k<=amount;k++)
     { 
            if(k%coins[0]==0) dp[0][k]=k/coins[0];
            else dp[0][k]=1e5;
        }
        
        for(int i=1;i<coins.size();i++){
            for(int sum=1;sum<=amount;sum++){
                  int not_take=0+dp[i-1][sum];
        int take=1e5;
        if(coins[i]<=sum)take=1+dp[i][sum-coins[i]];

       dp[i][sum]=min(take,not_take);
            }
        }
      
    //    if(ans==1e9)return -1;
     int ans= dp[coins.size()-1][amount];
     if(ans>=1e5)return -1;
     return ans;
    }
};