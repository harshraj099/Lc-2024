class Solution {
public:
        int f(int prev,int curr,int n,vector<vector<int>>& pairs, vector<vector<int>>&dp){
            if(curr==n || prev>curr)return 0;

            if(dp[prev+1][curr]!=-1)return dp[prev+1][curr];
            // take
            int take=0;
            if(prev==-1 || pairs[prev][1]<pairs[curr][0]){
                take=1+f(curr,curr+1,n,pairs,dp);
            }

            // leave
            int leave=f(prev,curr+1,n,pairs,dp);

            return dp[prev+1][curr]=max(leave,take);
        }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
       return f(-1,0,n,pairs,dp);
    }
};