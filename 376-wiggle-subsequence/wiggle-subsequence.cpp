class Solution {
public:
    int f(int prev,int curr,int sum,int n,vector<int>& nums,vector<vector<int>>&dp){
        if(curr>=n || prev>curr)return 0;
        
        if(dp[prev][curr]!=-1)return dp[prev][curr];
        int take=0;
        if((nums[curr]-nums[prev])>0 && (sum<0 || sum==1e8)){
            take=1+f(curr,curr+1,nums[curr]-nums[prev],n,nums,dp);
        }
        else if((nums[curr]-nums[prev])<0 && (sum>0 || sum==1e8)){
            take=1+f(curr,curr+1,nums[curr]-nums[prev],n,nums,dp);
        }

        int leave=f(prev,curr+1,sum,n,nums,dp);

        int leaveBoth=0;
        // if(prev==curr)leaveBoth=f(prev+1,curr+1,sum,n,nums,dp);

        return dp[prev][curr]=max(leaveBoth,max(take,leave)) ;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       return 1+f(0,0,1e8,n,nums,dp);
    }
};