class Solution {
public:
    int solve(vector<int>& nums, int index, int prevIndex, vector<vector<int>>& dp) {
        
        if (index == nums.size()) {
            return 0;
        }

        if (dp[index][prevIndex + 1] != -1) {
            return dp[index][prevIndex + 1];
        }

        int skip = solve(nums, index + 1, prevIndex, dp);

        int include = 0;
        if (prevIndex == -1 || nums[index] == nums[prevIndex] * nums[prevIndex]) {
            include = 1 + solve(nums, index + 1, index, dp);
        }

        return dp[index][prevIndex + 1] = max(include, skip);
    }

    // int longestSquareStreak(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    //     // int maxLength = solve(nums, 0, -1, dp);
    //     // return maxLength >= 2 ? maxLength : -1;

    //     int n = nums.size();
    //     vector<int> dp(n + 1, 0);  
    //     int maxLength = 0;

    //     for (int index = n - 1; index >= 0; index--) {
    //         int currentMax = 0;
    //         for (int nextIndex = index + 1; nextIndex < n; nextIndex++) {
    //             if (static_cast<long long>(nums[index]) * nums[index] == nums[nextIndex]) {
    //                 currentMax = max(currentMax, dp[nextIndex]);
    //             }
    //         }
    //         dp[index] = 1 + currentMax;
    //         maxLength = max(maxLength, dp[index]);
    //     }

    //     return maxLength >= 2 ? maxLength : -1;
    // }

    int longestSquareStreak(vector<int>& nums) {
        
        unordered_map<int, int> dp;
        int res = 0;
        sort(begin(nums), end(nums));

        for(auto i : nums){
            int root = sqrt(i);
            if(root * root == i)
                dp[i] = 1 + dp[root];
            else 
                dp[i] = 1;
            res = max(res, dp[i]);
        }
        return res < 2 ? -1 : res;
    }
};