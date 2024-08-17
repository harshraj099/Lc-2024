class Solution {
public:
    int f(int i,int j,int n,int m,string &s, string &p, vector<vector<int>>&dp){
        if(i>=n && j>=m)return 1;
        if(i>=n && j<m){
            while(j<m){
                if(p[j]!='*')return 0;
                j++;
            }
            return 1;
        }
        if(i<n && j>=m)return 0;


        if(dp[i][j]!=-1)return dp[i][j];
        
       int take=0,not_take=0;
        if(s[i]==p[j] | p[j]=='?')take=f(i+1,j+1,n,m,s,p,dp);
        else if(p[j]=='*') not_take=f(i+1,j,n,m,s,p,dp)|f(i,j+1,n,m,s,p,dp);  //some characters or zero characters
        else return 0;

        return  dp[i][j]=take|not_take;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
       int m=p.size();;
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(0,0,n,m,s,p,dp);

         // tabulation
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // base
        dp[0][0]=1;
        for(int j=1;j<=m;j++){
       if(p[j-1]=='*')dp[0][j]=1;
          else  break;   
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           int take=0,not_take=0;
        if(s[i-1]==p[j-1] | p[j-1]=='?')take=dp[i-1][j-1];
        else if(p[j-1]=='*') not_take=dp[i-1][j]|dp[i][j-1];
        // else dp[i][j]=0;

         dp[i][j]=take|not_take;
            }
        }
        return dp[n][m];

    }
};