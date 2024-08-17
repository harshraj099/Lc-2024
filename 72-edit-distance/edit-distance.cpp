class Solution {
public:
     int f(int i,int j,int n,int m,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n)return m-j;
        if(j>=m)return n-i;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=1e9,state=1e9;
        if(text1[i]==text2[j])take=f(i+1,j+1,n,m,text1,text2,dp);
        else state=1+min(f(i,j+1,n,m,text1,text2,dp),//insert
                        min(f(i+1,j,n,m,text1,text2,dp),//delete
                        f(i+1,j+1,n,m,text1,text2,dp)));//replace

        return  dp[i][j]=min(take,state);
    }
    int minDistance(string word1, string word2) {
         int n=word1.size();
        int m=word2.size();;
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(0,0,n,m,word1,word2,dp);
        
        // tabulation
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        // base
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           int take=1e9,state=1e9;
        if(word1[i-1]==word2[j-1])take=dp[i-1][j-1];
       else state=1+min(dp[i][j-1],//insert
                        min(dp[i-1][j],//delete
                        dp[i-1][j-1]));//replace

         dp[i][j]=min(take,state);
            }
        }
        return dp[n][m];
    }
};