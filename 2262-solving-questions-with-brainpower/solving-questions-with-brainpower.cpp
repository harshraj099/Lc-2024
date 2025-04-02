class Solution {
public:
    long long f(int idx,vector<vector<int>>& questions,int n,vector<long long>&dp){
        if(idx>=n)return 0;

        if(dp[idx]!=-1)return dp[idx];
        // take 
        long long  take=questions[idx][0]+f(idx+questions[idx][1]+1,questions,n,dp);

        // leave
        long long leave = f(idx+1,questions,n,dp);

        return dp[idx]=max(take,leave);

    }
    long long mostPoints(vector<vector<int>>& questions) {
       long long n=questions.size();
       vector<long long>dp(n,-1);
       return f(0,questions,n,dp); 
    }
};