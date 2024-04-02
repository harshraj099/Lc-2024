class Solution {
public:
       // if fl=0 buy stock ,fl=1 sell before buying
    int f(int i,vector<int>& prices,int n,  vector<vector<vector<int>>>&dp,int fl, int limit){
        if(limit==2 || i==n)  return 0;
        if(dp[i][fl][limit]!=-1)return dp[i][fl][limit];
        // buy 
        int profit=0;  //minimun to zero hi hoga logically
      if(fl==0) profit=max(-prices[i]+f(i+1,prices,n,dp,!fl,limit),0+f(i+1,prices,n,dp,fl,limit));
      // sell
     if(fl) profit=max(prices[i]+f(i+1,prices,n,dp,!fl,limit+1),0+f(i+1,prices,n,dp,fl,limit));

      return  dp[i][fl][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
                // int n=prices.size();
                // dp of n*2*3
                //2-> buy or sell
                // 3 limit at most 2 transction
    //    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //    return f(0,prices,n,dp,0,0);

       // tabulation
         int n=prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //basecase
        // if(limit==2 || i==n)  return 0;
        dp[n][0][2]=0;
        dp[n][1][2]=0;
        int profit=0;
          for(int i=n-1;i>=0;i--){
            for(int fl=0;fl<=1;fl++){
                for(int cap=1;cap>=0;cap--){
                    //buy
    if(fl==0) profit=max(-prices[i]+dp[i+1][!fl][cap],0+dp[i+1][fl][cap]);
      // sell
     if(fl) profit=max(prices[i]+dp[i+1][!fl][cap+1],0+dp[i+1][fl][cap]);
           dp[i][fl][cap]=profit;
                }
            }
        }
        return dp[0][0][0]; 
    }
};