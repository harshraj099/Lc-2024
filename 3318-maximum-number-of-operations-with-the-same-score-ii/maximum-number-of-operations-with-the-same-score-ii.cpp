class Solution {
public:
    int f(int i,int j,vector<int>& nums,int sum, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int l=0;
        if(i+1<=j){
            int ss=nums[i]+nums[i+1];
            if(sum==0 || ss==sum)l=1+f(i+2,j,nums,ss,dp);
        }
         int r=0;
        if(i<=j-1){
            int ss=nums[j]+nums[j-1];
            if(sum==0 || ss==sum)r=1+f(i,j-2,nums,ss,dp);
        }
         int m=0;
        if(i!=j){
            int ss=nums[i]+nums[j];
            if(sum==0 || ss==sum)m=1+f(i+1,j-1,nums,ss,dp);
        }
        return dp[i][j]=max(l,max(r,m));
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,nums,0,dp);
    }
};