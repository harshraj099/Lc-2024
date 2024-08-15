class Solution {
public:
    long long f(long long i,long long j,long long n,long long m,string &text1, string &text2, vector<vector<long long>>&dp){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        long long take=0;
        if(text1[i]==text2[j])take=1+f(i+1,j+1,n,m,text1,text2,dp);
        long long not_take=max(f(i+1,j,n,m,text1,text2,dp),max(f(i,j+1,n,m,text1,text2,dp),f(i+1,j+1,n,m,text1,text2,dp)));

        return  dp[i][j]=max(take,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        long long n=text1.size();
        long long m=text2.size();;
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return f(0,0,n,m,text1,text2,dp);
    }
};