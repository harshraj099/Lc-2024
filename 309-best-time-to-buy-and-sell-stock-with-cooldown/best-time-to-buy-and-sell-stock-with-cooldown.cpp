class Solution {
public:
    int f(int idx,int n,vector<int>& prices,int num, vector<vector<int>>&dp){
        if(idx>=n)return 0;
        
        if(dp[idx][num+1]!=-1)return dp[idx][num+1];
        // take
        int take=0;
       if(num==-1) take=f(idx+1,n,prices,idx,dp);

        // leave
        int leave=f(idx+1,n,prices,num,dp);
        
        // calculate
        int calculate=0;
       if(num!=-1 && prices[num]<prices[idx]) calculate=prices[idx]-prices[num]+f(idx+2,n,prices,-1,dp);

        return  dp[idx][num+1]=max(take,max(leave,calculate));
    }
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return  f(0,n,prices,-1,dp);  
    }
};