class Solution {
public:

    bool f(int alice,int bob,int n, vector<int>&dp){
        if(bob && n==1)return true;
        if(alice && n==1)return false;

        if(dp[n]!=-1)return dp[n];
        int takeb=0,takea=0;
        for(int i=1;i<n;i++){
            if(alice && n%i==0){
                // take
                takea=f(!alice,!bob,n-i,dp);
            }
            if(bob && n%i==0){
                // take
                takeb=f(!alice,!bob,n-i,dp);
            }
        }

        return  dp[n]=takea|takeb;

    }
    bool divisorGame(int n) {
        vector<int>dp(n+1,-1);
        return f(1,0,n,dp);
    }
};