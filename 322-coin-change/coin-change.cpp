class Solution {
public:
    int f(int idx,int n,vector<int>& coins, int target,vector<vector<int>>&dp)
    {
        if(target==0)return 0;

        if(idx>=n)return 1e8;

        if(dp[idx][target]!=-1)return dp[idx][target];
        // take
        int take=1e8;
        // cout<<idx<<endl;
        if(target>=coins[idx])take=1+f(idx,n,coins,target-coins[idx],dp);

        // leave
        int leave=f(idx+1,n,coins,target,dp);

        return  dp[idx][target]=min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //   if(f(0,n,coins,amount,dp)>=1e8)return -1;
    //   return f(0,n,coins,amount,dp);

    //   tabulation
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e8));
        // basecase
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int idx=1;idx<=n;idx++){
            for(int target=0;target<=amount;target++){
             // take
            int take=1e8;
        if(target>=coins[idx-1])take=1+dp[idx][target-coins[idx-1]];

        // leave
        int leave=dp[idx-1][target];

          dp[idx][target]=min(take,leave);
            }
        }
       
       if(dp[n][amount]>=1e8)return -1;
       return dp[n][amount];
    }
};