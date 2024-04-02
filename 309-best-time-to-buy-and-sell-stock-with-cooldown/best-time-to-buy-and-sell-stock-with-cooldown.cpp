class Solution {
public:
        // if fl=0 buy stock ,fl=1 sell before buying
    int f(int i,vector<int>& prices,int n,vector<vector<int>>&dp,int fl){
        if(i>=n)  return 0;
        if(dp[i][fl]!=-1)return dp[i][fl];
        // buy 
        int profit=0;  //minimun to zero hi hoga logically
      if(fl==0) profit=max(-prices[i]+f(i+1,prices,n,dp,!fl),0+f(i+1,prices,n,dp,fl));
      // sell
      // i+2 hogi kyuki after sell cool down
     if(fl) profit=max(prices[i]+f(i+2,prices,n,dp,!fl),0+f(i+1,prices,n,dp,fl));

      return  dp[i][fl]=profit;
    }
    int maxProfit(vector<int>& prices) {
    //             int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //    return f(0,prices,n,dp,0);

       // tabulation
         int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //basecase
        dp[n][0]=0;
        dp[n][1]=0;
          dp[n+1][0]=0;
        dp[n+1][1]=0;
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