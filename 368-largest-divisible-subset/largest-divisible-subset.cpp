class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        sort(nums.begin(),nums.end());
        vector<int> hash(n);
        vector<int>dp(n,1);
        int idx=0;
        for(int i=0;i<n;i++){
                hash[i]=i;
                for(int prev=0;prev<i;prev++){
                    if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                        dp[i]=dp[prev]+1;
                        hash[i]=prev;
                    }
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    idx=i;
                }
        }
        vector<int>ans;
        while(hash[idx]!=idx){
            ans.push_back(nums[idx]);
            idx=hash[idx];
        }
            ans.push_back(nums[idx]);
            reverse(ans.begin(),ans.end());
            return ans;
    }
};