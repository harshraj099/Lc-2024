class Solution {
public:
    int f(int i,vector<int>& prices, int fee,int isbought,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][isbought]!=-1)return dp[i][isbought];
        // buy or leave
        int buy=0;
        if(!isbought)buy=max(-prices[i]+f(i+1,prices,fee,!isbought,dp),f(i+1,prices,fee,isbought,dp));

        // sell or leave
        int sell=0;
        if(isbought)sell=max(prices[i]-fee+f(i+1,prices,fee,!isbought,dp),
        f(i+1,prices,fee,isbought,dp));

        return dp[i][isbought]=max(buy,sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
       return f(0,prices,fee,0,dp);
    }
};