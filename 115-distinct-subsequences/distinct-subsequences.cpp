class Solution {
public:
   	  int f(int i,int j,int n,int m,string &text1, string &t, vector<vector<int>>&dp){
        if(j>=m)return 1;
        if(i>=n && j<m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==t[j])take=f(i+1,j+1,n,m,text1,t,dp)+f(i+1,j,n,m,text1,t,dp);
        else not_take=f(i+1,j,n,m,text1,t,dp);

        return  dp[i][j]=take+not_take;
    }
    int numDistinct(string s, string t) {
        //        int n=s.size();
        // int m=t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(0,0,n,m,s,t,dp);

        // tabulation
             long long n=s.size();
        long long m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        // base
        for(int i=0;i<=n;i++)dp[i][0]=1;  // make table to understand
// since in memorization , for all column >m return 1, i.e all row after >=m are 1
// reverse in now all row before column 1 are one i.e for m==0 all rows (n) are 1
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           int take=0,not_take=0;
        if(s[i-1]==t[j-1])take=dp[i-1][j-1]+dp[i-1][j];
        else not_take=dp[i-1][j];

         dp[i][j]=take+not_take;
            }
        }
        return dp[n][m];
    }
};