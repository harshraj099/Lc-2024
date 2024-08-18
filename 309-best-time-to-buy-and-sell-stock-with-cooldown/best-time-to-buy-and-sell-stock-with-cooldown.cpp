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
    //     int n=prices.size();
    //    vector<vector<int>>dp(n,vector<int>(2,-1));
    //    return f(0,n,prices,dp,0);

       // tabulation
         int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //basecase
        int profit=0;
        for(int i=n-1;i>=0;i--){
            //buy
            for(int fl=0;fl<=1;fl++){
    if(fl==0) profit=max(-prices[i]+dp[i+1][!fl],0+dp[i+1][fl]);
      // sell
     if(fl) profit=max(prices[i]+dp[i+2][!fl],0+dp[i+1][fl]);
           dp[i][fl]=profit;
            }
        }
        return dp[0][0];
    }
};