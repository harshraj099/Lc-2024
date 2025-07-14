class Solution {
public:
        int f(int l,int r,vector<int>& cuts,int i,int j,vector<vector<int>>&dp){
            if(i>j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            int mini=1e9;
            for(int k=i;k<=j;k++){
            int cut=(r-l)+f(l,cuts[k],cuts,i,k-1,dp) + f(cuts[k],r,cuts,k+1,j,dp); 
            mini=min(cut,mini);    
            }
            return dp[i][j]=mini;
        }
    int minCost(int N, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int n=cuts.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,N,cuts,0,cuts.size()-1,dp);
    }
};