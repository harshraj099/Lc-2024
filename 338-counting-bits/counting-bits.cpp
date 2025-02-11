class Solution {
public:
    int f(int i,vector<int>&dp){
        if(i==0)return 0;
        if(dp[i]!=-1)return dp[i];
        // take
        int take=0,leave=0;
       if((i & 1))take=1+f(i>>1,dp);
        else leave=f(i>>1,dp);

        return dp[i]=take+leave;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        vector<int>dp(n+1,-1);
        dp[0]=0;
         for(int i=1;i<=n;i++){
         int ct= f(i,dp);
        ans.push_back(ct);
        }

        return ans;
    }
};