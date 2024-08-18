class Solution {
public:
    int f(int ind,int n,vector<int>& prices,vector<vector<int>>&dp,int fl){
    if(ind>=n)return 0;
    if(dp[ind][fl]!=-1) return dp[ind][fl];
    // buy
    int profit=0;
    if(!fl)profit=max(-prices[ind]+f(ind+1,n,prices,dp,!fl),f(ind+1,n,prices,dp,fl));
    // sell
    if(fl)profit=max(prices[ind]+f(ind+2,n,prices,dp,!fl),f(ind+1,n,prices,dp,fl));

     return  dp[ind][fl]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,n,prices,dp,0);

       
    }
};