class Solution {
public:
int solve1(int idx,vector<int>& arr,vector<int>&dp){
	    if(idx<=0)return 0;
        if(idx==1)return arr[idx];
	    if(dp[idx]!=-1)return dp[idx];
	    //take
	    int pick=solve1(idx-2,arr,dp)+arr[idx];
	    //not take
	    int notpick=solve1(idx-1,arr,dp);
	    return dp[idx]=max(pick,notpick);
	}
    int solve2(int idx,vector<int>& arr,vector<int>&dp){
        if(idx<0)return 0;
	    if(idx==0)return arr[0];
	    if(dp[idx]!=-1)return dp[idx];
	    //take
	    int pick=solve2(idx-2,arr,dp)+arr[idx];
	    //not take
	    int notpick=solve2(idx-1,arr,dp);
	    return dp[idx]=max(pick,notpick);
	}
    int rob(vector<int>& nums) {
            int n=nums.size();
            if(n==1)return nums[0];
           vector<int>dp(n,-1);
	int  ans1= solve1(n-1,nums,dp);
     vector<int>dpp(n,-1);
    int  ans2= solve2(n-2,nums,dpp);
    return max(ans1,ans2);
    }
};