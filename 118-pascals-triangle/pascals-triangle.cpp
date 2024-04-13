class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec;
        vector<vector<int>>dp(numRows,vector<int>(numRows,0));
        // basecase
        for(int i=0;i<numRows;i++)dp[i][0]=1;
        vec.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>v;
                v.push_back(dp[i][0]);
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                v.push_back(dp[i][j]);
            }
            vec.push_back(v);
        }
        return vec;
    }
};