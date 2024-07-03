class Solution {
public:
    int minDifference(vector<int>& nums) {
       sort(nums.begin(),nums.end());

        if(nums.size()<4)return 0;

        int diff=INT_MAX;
       diff=min(diff,nums[nums.size()-1]-nums[3]);
       diff=min(diff,nums[nums.size()-4]-nums[0]);
       diff=min(diff,nums[nums.size()-2]-nums[2]);
       diff=min(diff,nums[nums.size()-3]-nums[1]);

    return diff;
    }
};