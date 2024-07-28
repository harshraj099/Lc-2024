class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // find lower bound and insert at its position

        //return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // or
        int low =0;
        int high=nums.size()-1;
        int ans=nums.size();
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                // ans=mid;
                high=mid-1;
            }
            else {
                // ans=mid;
                low=mid+1;
            }
        }
        return low;
    }
};