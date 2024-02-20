class Solution {
public:
        int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
            if(i==n-1)return dp[i][j]=triangle[i][j];
            if(dp[i][j]!=-1)return dp[i][j];
            int down=triangle[i][j]+f(i+1,j,n,triangle,dp);
            int diagonal=triangle[i][j]+f(i+1,j+1,n,triangle,dp);

            return dp[i][j]=min(down,diagonal);
        }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,triangle,dp);
    }
};