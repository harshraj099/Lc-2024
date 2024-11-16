class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        if(k==1)return nums;
        int n = nums.size();
        int l=0,r=1;
        while(r<n){
            bool not_con=(nums[r]!=nums[r-1]+1)?1:0;
            
            if(not_con){
                while(l<r && l<=n-k){
                    res.push_back(-1);
                    l++;
                }
            }

            if(r-l==k-1){
                res.push_back(nums[r]);
                l++;
            }
            r++;
        }
    
        // for (int i = 0; i <= n - k; i++) {
        //     // Extract the subarray of size k starting at index i
        //     bool isConsecutive = true;
        //     for (int j = 1; j < k; j++) {
        //         if (nums[i + j] != nums[i + j - 1] + 1) {
        //             isConsecutive = false;
        //             break;
        //         }
        //     }
        //     if (isConsecutive) {
        //         res.push_back(nums[i + k - 1]); // Max element of a sorted subarray is the last element
        //     } else {
        //         res.push_back(-1); // Subarray is not consecutive
        //     }
        // }

        return res;
    }
};
