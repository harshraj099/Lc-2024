class Solution {
public:int f(int ind,int n,vector<int>& prices,vector< vector<vector<int>>>&dp,int fl,int bond){
    if(ind==n || bond==2)return 0;
    if(dp[ind][fl][bond]!=-1)return dp[ind][fl][bond];
    // buy
    int profit=0;
    if(!fl)profit=max(-prices[ind]+f(ind+1,n,prices,dp,!fl,bond),f(ind+1,n,prices,dp,fl,bond));
    // sell
    if(fl)profit=max(prices[ind]+f(ind+1,n,prices,dp,!fl,bond+1),f(ind+1,n,prices,dp,fl,bond));

     return  dp[ind][fl][bond]=profit;
}
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
       vector< vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return f(0,n,prices,dp,0,0);
    }
};