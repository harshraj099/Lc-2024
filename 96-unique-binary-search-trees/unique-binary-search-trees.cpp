class Solution {
public:
    // int sum=0;
     long long f( long long left, long long right, vector<vector<long long>>&dp){
        
        if(left>right)return 1;
        if (dp[left][right] != -1) return dp[left][right];

        long long ways=0;
        for(int i=left;i<=right;i++){
            // left
            long long l=f(left,i-1,dp);
            // right
            long long r= f(i+1,right,dp);

            ways+=l*r;
        }

        return dp[left][right]= ways;
    }
    int numTrees(int n) {
    vector<vector<long long>>dp(n + 1, vector<long long>(n + 1, -1)); 
      return  f(1,n,dp);
    }
};