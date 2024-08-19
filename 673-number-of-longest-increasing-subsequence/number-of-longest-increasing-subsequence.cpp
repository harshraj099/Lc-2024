class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
             int n=nums.size();
             int maxi=0;
             int ct=0;
        vector<int>dp(n,1),hash(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[prev]+1>dp[i]){
                  dp[i]=1+dp[prev];
                        hash[i]=hash[prev];
                    }
                  else if(nums[i]>nums[prev] && dp[prev]+1==dp[i]) hash[i]+=hash[prev];
                }
             maxi=max(maxi,dp[i]);  
        }

        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ct+=hash[i];
        }
        // if(ct==0)return n;
        return ct;
    }
};