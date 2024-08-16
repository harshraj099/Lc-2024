class Solution {
public:
  int f(int i,int j,int n,int m,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==text2[j])take=1+f(i+1,j+1,n,m,text1,text2,dp);
        else not_take=max(f(i+1,j,n,m,text1,text2,dp),f(i,j+1,n,m,text1,text2,dp));

        return  dp[i][j]=max(take,not_take);
    }
    int minDistance(string word1, string word2) {
          int n=word1.size();
        int m=word2.size();
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    //  int res=f(0,0,n,m,word1,word2,dp);
    //  return n-res+m-res;
      // tabulation
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
          int take=0,not_take=0;
        if(word1[i-1]==word2[j-1])take=1+dp[i-1][j-1];
        else not_take=max(dp[i-1][j],dp[i][j-1]);

         dp[i][j]=max(take,not_take);
            }
        }
        return n+m-2*dp[n][m];
    }
};