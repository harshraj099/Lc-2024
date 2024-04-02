class Solution {
public:
            // if fl=0 buy stock ,fl=1 sell before buying
    int f(int i,vector<int>& prices,int n,vector<vector<int>>&dp,int fl,int fee){
        if(i==n)  return 0;
        if(dp[i][fl]!=-1)return dp[i][fl];
        // buy 
        int profit=0;  //minimun to zero hi hoga logically
      if(fl==0) profit=max(-prices[i]+f(i+1,prices,n,dp,!fl,fee),0+f(i+1,prices,n,dp,fl,fee));
      // sell
     if(fl) profit=max(prices[i]-fee+f(i+1,prices,n,dp,!fl,fee),0+f(i+1,prices,n,dp,fl,fee));

      return  dp[i][fl]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,prices,n,dp,0,fee);
    }
};