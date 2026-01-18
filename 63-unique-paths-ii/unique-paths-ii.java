class Solution {
    int f(int i,int j,int m,int n,int[][] obstacleGrid,int [][]dp){
        if(i==m-1 && j==n-1)return 1;
        if(i==m || j==n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // down
        int down =0;
        if(i+1< m && obstacleGrid[i+1][j]!=1)down= f(i+1,j,m,n,obstacleGrid,dp);

        // right
        int right =0;
        if(j+1<n && obstacleGrid[i][j+1]!=1)right= f(i,j+1,m,n,obstacleGrid,dp);

        return   dp[i][j] =down + right ;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;

        if(obstacleGrid[0][0]==1)return 0;

        int [][]dp=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;

       return f(0,0,m,n,obstacleGrid,dp);
    }
}