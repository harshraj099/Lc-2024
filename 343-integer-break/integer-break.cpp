class Solution {
public:
   int f(int prev,int curr,int n,vector<vector<int>>&dp){
        if(curr>n)return 1;

        if(dp[prev][curr]!=-1)return dp[prev][curr];
        //divide
        int div=(curr-prev)*f(curr,curr+1,n,dp);

        // not divide
        int dnd=f(prev,curr+1,n,dp);

        return  dp[prev][curr]= max(div,dnd);
    }
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      return f(0,1,n,dp);
    }
};