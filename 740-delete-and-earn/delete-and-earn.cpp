class Solution {
public:
  
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
       int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        for(auto it:nums)points[it]+=it;

        vector<int>dp(maxVal + 1, 0);
        dp[0]=points[0];
        dp[1]=points[1];
        for(int i=2;i<maxVal+1;i++){
            int take=points[i]+dp[i-2];
            
            int leave=dp[i-1];

            dp[i]=max(take,leave);
        }

        return dp[maxVal];
    }
};