class Solution {
public:
int f(int i,int n,vector<int>&nums,int prev,vector<vector<int>>&dp){
    if(i==n)return 0;

    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    // take
    int take=0;
    if(prev==-1 ) take=1+f(i+1,n,nums,i,dp);
   else if(prev!=-1 && nums[i]>nums[prev])take=1+f(i+1,n,nums,i,dp);
    // leave
    int leave=f(i+1,n,nums,prev,dp);

    return dp[i][prev+1]= max(take,leave);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

    //    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //    return f(0,n,nums,-1,dp);
    //    tabulation 1
    //    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int prev=i-1;prev>=-1;prev--){
    //            int take=0;
    //             if(prev==-1 || nums[i]>nums[prev])take=1+dp[i+1][i+1];
    //          // leave
    //            int leave=dp[i+1][prev+1];

    //            dp[i][prev+1]= max(take,leave);   
    //         }
    //     }
    //     return dp[0][0];

        // tabulation 2
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
              if(nums[i]>nums[prev]) dp[i]=max(dp[i],1+dp[prev]);
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};