class Solution {
public:
    int f(int idx1,int idx2,string &text1, string &text2,vector<vector<int>>&dp){
        if(idx1==-1 || idx2==-1)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        // if matches on idx
        int take=0;
        if(text1[idx1]==text2[idx2]) take=1+f(idx1-1,idx2-1,text1,text2,dp);
        
        // not matches
        int nt=0;
       if(text1[idx1]!=text2[idx2])  nt=0+max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));

        return dp[idx1][idx2]=take+nt;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};