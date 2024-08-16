class Solution {
public:
         int f(int i,int j,int n,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n || j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==text2[j])take=1+f(i+1,j-1,n,text1,text2,dp);
        else not_take=max(f(i+1,j,n,text1,text2,dp),f(i,j-1,n,text1,text2,dp));

        return  dp[i][j]=max(take,not_take);
    }
    int minInsertions(string s) {
      int n=s.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //   return n- f(0,n-1,n,s,s,dp);
       // tabulation
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=n-1;j>=0;j--){
          int take=0,not_take=0;
        if(s[i-1]==s[j])take=1+dp[i-1][j+1];
        else not_take=max(dp[i-1][j],dp[i][j+1]);

         dp[i][j]=max(take,not_take);
            }
        }
        return n-dp[n][0];
    }
};