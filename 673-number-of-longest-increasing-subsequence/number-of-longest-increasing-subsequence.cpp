class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=0;
        vector<int>freq(n,1);
        freq[0]=1;
        int ct=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    freq[i]=freq[prev];
                }
                else if(nums[i]>nums[prev] && dp[prev]+1==dp[i])freq[i]+=freq[prev];
            }
            maxi=max(dp[i],maxi);
        }
        for(int i=0;i<n;i++) if(maxi==dp[i])ct+=freq[i];
        return ct;
    }
};