class Solution {
public:
    // long long f(long long i,long long j,long long n,long long m,string &text1, string &text2, vector<vector<long long>>&dp){
    //     if(i>=n || j>=m)return 0;

    //     if(dp[i][j]!=-1)return dp[i][j];
    //     // take
    //     long long take=0,not_take=0;
    //     if(text1[i]==text2[j])take=1+f(i+1,j+1,n,m,text1,text2,dp);
    //     else not_take=max(f(i+1,j,n,m,text1,text2,dp),f(i,j+1,n,m,text1,text2,dp));

    //     return  dp[i][j]=max(take,not_take);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        long long n=text1.size();
        long long m=text2.size();;
        // vector<vector<long long>>dp(n,vector<long long>(m,-1));
        // return f(0,0,n,m,text1,text2,dp);

        // tabulation
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));

        // base
        // if(text1[0]==text2[0])dp[0][0]=1;
        // for(int i=1;i<n;i++){
        // if(text1[i]==text2[0])dp[i][0]=1+dp[i-1][0];
        // else dp[i][0]=dp[i-1][0];
        // }
        // for(int j=1;j<m;j++){
        // if(text1[0]==text2[j])dp[0][j]=1+dp[0][j-1];
        // else dp[0][j]=dp[0][j-1];
        // }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           long long take=0,not_take=0;
        if(text1[i-1]==text2[j-1])take=1+dp[i-1][j-1];
        else not_take=max(dp[i-1][j],dp[i][j-1]);

         dp[i][j]=max(take,not_take);
            }
        }
        return dp[n][m];
    }
};