class Solution {
public:
    int f(int idx,vector<int>& cost,int n,vector<int>&dp){
        if(idx>=n)return 0;

       if(dp[idx]!=-1)return dp[idx];
        // take 1 step
        int step1=0,step2=0;
        if(idx==0){
        step1=min(cost[idx]+f(idx+1,cost,n,dp),cost[idx+1]+f(idx+2,cost,n,dp));
        }
        else{
             step1=cost[idx]+f(idx+1,cost,n,dp);
        }

        // take 2 step
         if(idx==0){
        step2=min(cost[idx]+f(idx+2,cost,n,dp),cost[idx+1]+f(idx+3,cost,n,dp));
        }
        else{
             step2=cost[idx]+f(idx+2,cost,n,dp);
        }

        return dp[idx] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
       return f(0,cost,n,dp);
    }
};