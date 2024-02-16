class Solution {
public:
	int solve(int idx,vector<int>& arr,vector<int>&dp){
	    if(idx<0)return 0;
	    if(idx==0)return arr[0];
	    if(dp[idx]!=-1)return dp[idx];
	    //take
	    int pick=solve(idx-2,arr,dp)+arr[idx];
	    //not take
	    int notpick=solve(idx-1,arr,dp);
	    return dp[idx]=max(pick,notpick);
	}
    int rob(vector<int>& nums) {
        int n=nums.size();
           vector<int>dp(n,-1);
	    
	return solve(n-1,nums,dp);
    }
};