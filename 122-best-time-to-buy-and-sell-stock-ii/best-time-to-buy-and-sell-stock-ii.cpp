class Solution {
public:
    int f(int idx,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
        if(idx==n)return 0;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit=0;
        if(!buy)profit=max(-prices[idx]+f(idx+1,!buy,prices,n,dp),f(idx+1,buy,prices,n,dp));
        else profit=max(prices[idx]+f(idx+1,!buy,prices,n,dp),f(idx+1,buy,prices,n,dp));
        
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,0,prices,n,dp);
    }
};