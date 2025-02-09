class Solution {
public:

    int f(int idx,int n,string curr,string s,vector<int>&dp){
        if(s[idx]=='0')return 0;
        if(idx>=n)return 1;

        if(dp[idx]!=-1)return dp[idx];
        // take one each
        int take1=f(idx+1,n,curr,s,dp);

        // take 2 each
        int take2=0;
       if(idx+1<n && curr+s[idx]+s[idx+1]<"27") take2=f(idx+2,n,curr,s,dp);

        return  dp[idx]=take1+take2;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
       return f(0,n,"",s,dp);
    }
};