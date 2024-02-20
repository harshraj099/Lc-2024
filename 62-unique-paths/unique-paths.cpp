class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)return dp[i][j]=1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int top=f(i,j-1,dp);
        int left=f(i-1,j,dp);

        return dp[i][j]=top+left;
    }
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
//    return f(m-1,n-1,dp);
    // return dp[m-1][n-1];   // or

    // tabulation
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i==0 && j==0)dp[i][j]=1;
        else {
            int top;
        if(j-1>=0)top=dp[i][j-1];
        if(j-1<0)top=0;
        int left;
        if(i-1>=0)left=dp[i-1][j];
        if(i-1<0)left=0;
         dp[i][j]=top+left;
        }
    }
}
return dp[m-1][n-1];
    }
};