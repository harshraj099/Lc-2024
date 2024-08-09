class Solution {
public:
        int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
                        if(j<0 || j>=n) return 1e5;
            if(i==n-1) return dp[i][j]=matrix[i][j];
            if(dp[i][j]!=-1)return dp[i][j];
            int down=matrix[i][j]+f(i+1,j,n,matrix,dp);
            int left_diagonal=matrix[i][j]+f(i+1,j-1,n,matrix,dp);
            int right_diagonal=matrix[i][j]+f(i+1,j+1,n,matrix,dp);
      
            return dp[i][j]=min(down,min(left_diagonal,right_diagonal));
        }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        //  vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int j=0;j<n;j++){    
        //     ans=min(ans,f(0,j,n,matrix,dp));
        // }
        // return ans;

        // tabulation
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
      if(n==1)ans=min(ans,dp[0][j]);
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
            int down=matrix[i][j];
            down+=dp[i-1][j];
            int left_diagonal=matrix[i][j];
              if(j+1<n)left_diagonal+=dp[i-1][j+1];
              else left_diagonal=1e5;
            int right_diagonal=matrix[i][j];
             if( j-1>=0)right_diagonal+=dp[i-1][j-1];
              else right_diagonal=1e5;

                dp[i][j]=min(down,min(left_diagonal,right_diagonal));
                if(i==n-1)ans=min(ans,dp[i][j]);
            }
              
        }
        // if(ans>=1e5)return *min_element(matrix[0].begin(),matrix[0].end());
        return ans;
    }
};