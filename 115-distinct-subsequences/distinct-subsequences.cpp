class Solution {
public:
   	  int f(int i,int j,int n,int m,string &text1, string &text2, vector<vector<int>>&dp){
        if(j>=m)return 1;
        if(i>=n && j<m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==text2[j])take=f(i+1,j+1,n,m,text1,text2,dp)+f(i+1,j,n,m,text1,text2,dp);
        else not_take=f(i+1,j,n,m,text1,text2,dp);

        return  dp[i][j]=take+not_take;
    }
    int numDistinct(string s, string t) {
                int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,s,t,dp);

        //tabulation

        // base case
        //  int n=s.size();
        // int m=t.size();
        // vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        // //  if(j<=0)return 1;
        // // if(i<=0)return 0;
        // for(int i=0;i<=n;i++)dp[i][0]=1;
        //  for(int j=1;j<=m;j++)dp[0][j]=0;

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        // if(s[i-1]==t[j-1]) dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
        //        else  dp[i][j]= dp[i-1][j];
        //     }
        // }
        // // return (int)dp[n][m];
        // //or
        // return dp[n][m];

    }
};