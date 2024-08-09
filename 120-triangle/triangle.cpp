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
        // vector<vector<int>>dp(n,vector<int>(m,-1));
    //   return  f(0,0,n,triangle,dp);

      // tabulation
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
            int down=1e9;
            if(i-1>=0)down=triangle[i][j]+dp[i-1][j];
            int diagonal=1e9;
           if(i-1>=0 && j-1>=0)diagonal=triangle[i][j]+dp[i-1][j-1];

             dp[i][j]=min(down,diagonal);
            //  cout<<dp[i][j]<<endl;
            }
            // cout<<endl;
        }
int mini=1e9;
for(int i=0;i<m;i++)mini=min(mini,dp[n-1][i]);
return mini;


      for(int j=0;j<n;j++){
          dp[n-1][j]=triangle[n-1][j];
      }
      for(int i=n-2;i>=0;i--){
          for(int j=i;j>=0;j--){
              int down=triangle[i][j]+dp[i+1][j];
             int diagonal=triangle[i][j]+dp[i+1][j+1];
             dp[i][j]=min(down,diagonal);
          }
      }

      return dp[0][0];
    }
};