class Solution {
public:
    // if fl=0 buy stock ,fl=1 sell before buying
    int f(int i,vector<int>& prices,int n,vector<vector<int>>&dp,int fl){
        if(i==n)  return 0;
        if(dp[i][fl]!=-1)return dp[i][fl];
        // buy 
        int buy=0;  //minimun to zero hi hoga logically
      if(fl==0) buy=-prices[i]+f(i+1,prices,n,dp,!fl);
      // sell
      int sell=0;
     if(fl) sell=prices[i]+f(i+1,prices,n,dp,!fl);

    int leave=f(i+1,prices,n,dp,fl);

      return  dp[i][fl]=max({buy,sell,leave});
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,prices,n,dp,0);
    }
};