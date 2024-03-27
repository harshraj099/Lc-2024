class Solution {
public:
    int f(int idx1,int idx2,string &text1, string &text2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        // if matches on idx
        // int take=0;
        // if(text1[idx1]==text2[idx2]) take=1+f(idx1-1,idx2-1,text1,text2,dp);
        //or
       if(text1[idx1]==text2[idx2])  return 1+f(idx1-1,idx2-1,text1,text2,dp);
        
        // not matches
    //     int nt=0;
    //    if(text1[idx1]!=text2[idx2])  nt=0+max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));
       //or
    return  dp[idx1][idx2]=max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));

        // return dp[idx1][idx2]=take+nt;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,text1,text2,dp);

        // tabulation by shifted index
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m;i++)dp[0][i]=0;
        for(int i=0;i<n;i++)dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take=0;
                if(text1[i-1]==text2[j-1]) take=1+dp[i-1][j-1];

                 int nt=0;
       if(text1[i-1]!=text2[j-1])  nt=0+max(dp[i-1][j],dp[i][j-1]);

                dp[i][j]=take+nt;
            }
        }
        return dp[n][m];
    }
};