class Solution {
public:
        int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
     
        if(i<0 || j<0 || obstacleGrid[i][j]==1)return 0;
           if(i==0 && j==0)return dp[i][j]=1;
        if(dp[i][j]!=-1)return dp[i][j];
        int top=f(i,j-1,dp,obstacleGrid);
        int left=f(i-1,j,dp,obstacleGrid);

        return dp[i][j]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//          vector<vector<int>>dp(m,vector<int>(n,-1));
//    return f(m-1,n-1,dp,obstacleGrid);

//    tabulation
int n=obstacleGrid.size();
int m=obstacleGrid[0].size();
if(obstacleGrid[0][0]==1)return 0;
 vector<vector<int>>dp(n,vector<int>(m,0));
 dp[0][0]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                if(obstacleGrid[i][j]==0){
                    int down=0;
                    if(i-1>=0)down=dp[i-1][j];
                    int right=0;
                    if(j-1>=0)right=dp[i][j-1];

                    dp[i][j]=right+down;
                }
            }
        }

        return dp[n-1][m-1];
    }
};