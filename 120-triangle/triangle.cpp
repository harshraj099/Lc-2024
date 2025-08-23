class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        // tabulation
        vector<vector<int>>dp(n,vector<int>(m,1e9));
    //      for(int j=0;j<n;j++){
    //       dp[n-1][j]=triangle[n-1][j];
    //   }
      dp[0][0]=triangle[0][0];
      for(int i=1;i<n;i++){
          for(int j=0;j<=i;j++){
              int down=1e5;
             if(j<i) down=triangle[i][j]+dp[i-1][j];
             int diagonal=1e5;
            if(j-1>=0) diagonal=triangle[i][j]+dp[i-1][j-1];
             dp[i][j]=min(down,diagonal);
          }
      }
        int mini=1e9;
        for(int j=0;j<m;j++)mini=min(mini,dp[n-1][j]);
      return mini;
    }
};