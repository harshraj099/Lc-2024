class Solution {
public:
    void f(int idx,vector<int>& nums,vector<int>&res,vector<int>& temp){
        if(idx==nums.size()){
            if(temp.size()>res.size()){
                res=temp;
            }
            return;
        }

        // take
        if(temp.empty() || nums[idx]%temp.back()==0){
            temp.push_back(nums[idx]);
            f(idx+1,nums,res,temp);
            temp.pop_back();
        }

        // leave
        f(idx+1,nums,res,temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums;
        sort(nums.begin(),nums.end());
      
      vector<int>res,temp;
    //   f(0,nums,res,temp);
         vector<int> dp(n, 1), prev(n, -1);
        int max_idx = 0, max_size = 1;

        // Step 3: Populate the DP arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > max_size) {
                max_size = dp[i];
                max_idx = i;
            }
        }

        // Step 4: Reconstruct the largest divisible subse
        for (int i = max_idx; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
            if (prev[i] == -1) break;
        }      
        return res;
    }
};