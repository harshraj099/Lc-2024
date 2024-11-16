class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            // Extract the subarray of size k starting at index i
            bool isConsecutive = true;
            for (int j = 1; j < k; j++) {
                if (nums[i + j] != nums[i + j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive) {
                res.push_back(nums[i + k - 1]); // Max element of a sorted subarray is the last element
            } else {
                res.push_back(-1); // Subarray is not consecutive
            }
        }

        return res;
    }
};
