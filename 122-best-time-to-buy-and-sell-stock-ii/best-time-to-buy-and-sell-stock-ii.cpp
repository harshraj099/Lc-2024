class Solution {
public:
int f(int ind,int n,vector<int>& prices,vector<vector<int>>&dp,int cost,int fl){
    if(ind==n)return 0;
    if(dp[ind][fl]!=-1)return dp[ind][fl];
    // buy
    // int take=0;
    int profit=0;
    if(!fl)profit=max(-prices[ind]+f(ind+1,n,prices,dp,prices[ind],!fl),f(ind+1,n,prices,dp,prices[ind],fl));
    // sell
    // int not_take=0;
    if(fl)profit=max(prices[ind]+f(ind+1,n,prices,dp,0,!fl),f(ind+1,n,prices,dp,cost,fl));

     return  dp[ind][fl]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,n,prices,dp,0,0);
    }
};