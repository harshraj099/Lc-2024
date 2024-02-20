class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        //     for(int i=0;i<nums.size();i++){
        //         if(i!=nums[i])return i;
        //     }
        //     return nums.size();
            int ans=0;
              for(int i=0;i<nums.size();i++){
               ans=ans^nums[i];
            }
              for(int i=0;i<=nums.size();i++){
                    ans=ans^i;
            }
            return ans;
    }
};