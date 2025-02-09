class Solution {
public:
        int f(int num,int size,int n,vector<int>&dp){
            if(num>size || n<0)return 1e9;
            if(n==0)return 0;

            if(dp[n]!=-1)return dp[n];
            // take
            int take=1+f(num,size,n-num*num,dp);

            // leave
            int leave=f(num+1,size,n,dp);

            return  dp[n]=min(take,leave);
        }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
       return f(1,sqrt(n),n,dp);
    }
};