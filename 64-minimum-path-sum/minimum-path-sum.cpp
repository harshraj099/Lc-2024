class Solution {
public:
        int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
     
        if(i<0 || j<0)return 1e5;
           if(i==0 && j==0)return dp[i][j]=grid[i][j];
        if(dp[i][j]!=-1 )return dp[i][j];
        int top=grid[i][j]+ f(i,j-1,dp,grid);
        int left=grid[i][j] + f(i-1,j,dp,grid);
        return dp[i][j]=min(left,top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
//    return f(m-1,n-1,dp,grid);

   // tabulation
    dp[0][0]=grid[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        int top=grid[i][j];
        if(j-1>=0)top+=dp[i][j-1];
        if(j-1<0)top+=1e5;
        int left=grid[i][j];
        if(i-1>=0)left+=dp[i-1][j];
        if(i-1<0)left+=1e5;

        if(i==0 && j==0)dp[i][j]=grid[0][0];
        else dp[i][j]=min(left,top);
        }
    }
        return dp[m-1][n-1];

    }
};