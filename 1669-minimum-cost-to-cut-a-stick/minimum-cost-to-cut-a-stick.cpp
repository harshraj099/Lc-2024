class Solution {
public:
    int f(int i,int j,vector<int>& cuts, vector<vector<int>>&dp){
        if(i>j)return 0;
        int mini=1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        //check cut in every possible point
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return f(1,cuts.size()-2,cuts,dp);
    }
};