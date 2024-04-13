class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(rowIndex+1,vector<int>(rowIndex+1,0));
        // basecase
        for(int i=0;i<=rowIndex;i++)dp[i][0]=1;
        if(rowIndex==0)return {1};
        for(int i=1;i<=rowIndex;i++){
            vector<int>v;
             if(i==rowIndex)    v.push_back(dp[i][0]);
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
               if(i==rowIndex)  v.push_back(dp[i][j]);
            }
            if(i==rowIndex)return v;
        }
        return {};
    }
};