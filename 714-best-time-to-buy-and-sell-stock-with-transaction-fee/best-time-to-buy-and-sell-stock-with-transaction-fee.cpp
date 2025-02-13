class Solution {
public:
            // if fl=0 buy stock ,fl=1 sell before buying
    int f(int i,vector<int>& prices,int n,vector<vector<int>>&dp,int fl,int fee){
        if(i==n)  return 0;
        if(dp[i][fl]!=-1)return dp[i][fl];
        // buy 
        int buy=0; 
        if(!fl)buy=-prices[i]+f(i+1,prices,n,dp,!fl,fee);
        
        // sell
        int sell=0;
        if(fl)sell=prices[i]-fee+f(i+1,prices,n,dp,!fl,fee);

        // leave
        int leave=f(i+1,prices,n,dp,fl,fee);

      
      return  dp[i][fl]=max(leave,max(buy,sell));
    }
    int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f(0,prices,n,dp,0,fee);
    }
};