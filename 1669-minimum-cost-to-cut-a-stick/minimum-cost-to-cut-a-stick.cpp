class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=1e9;
        for(int idx=i;idx<=j;idx++){
            int sum=f(i,idx-1,cuts,dp)+f(idx+1,j,cuts,dp)+cuts[j+1]-cuts[i-1];
            mini=min(mini,sum);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
            int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        // vector<vector<int>>dp(m+2,vector<int>(m+2,-1));
        sort(cuts.begin(),cuts.end());
        // return f(1,cuts.size()-2,cuts,dp);
        // tabulation
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=i;j<m+1;j++){
             int mini=1e9;
        for(int idx=i;idx<=j;idx++){
            int sum=dp[i][idx-1]+dp[idx+1][j]+cuts[j+1]-cuts[i-1];
            mini=min(mini,sum);
        }
         dp[i][j]=mini;   
            }
        }
        return dp[1][m];
    }
};