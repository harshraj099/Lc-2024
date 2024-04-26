class Solution {
public:
    int f(int idx,int jdx,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(idx>=grid.size())return 0;

        if(dp[idx][jdx+1]!=-1)return dp[idx][jdx+1];

        int take=1e8;
        for(int j=0;j<grid[0].size();j++){
            if(j!=jdx){
                take=min(take,grid[idx][j]+f(idx+1,j,grid,dp));
            }
        }
        return dp[idx][jdx+1]=take;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>dp(n+1,vector<int>(m+2,-1));
       return f(0,-1,grid,dp);

    }
};