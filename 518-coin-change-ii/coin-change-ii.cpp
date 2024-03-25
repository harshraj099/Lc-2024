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
    //           vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
    //    int ans= f(coins.size()-1,coins,amount,dp);
    //    return ans;

       // tabulation 
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int k=0;k<=amount;k++)
     { 
            if(k%coins[0]==0) dp[0][k]=1;
            else dp[0][k]=0;
        }
        
        for(int i=1;i<coins.size();i++){
            for(int sum=0;sum<=amount;sum++){
                  int not_take=dp[i-1][sum];
        int take=0;
        if(coins[i]<=sum)take=dp[i][sum-coins[i]];

       dp[i][sum]=take+not_take;
            }
        }
      
     int ans= dp[coins.size()-1][amount];
     return ans;
    }
};