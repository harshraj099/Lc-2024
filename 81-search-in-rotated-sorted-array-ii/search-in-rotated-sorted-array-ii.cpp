class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return true;
            // if all equal
            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                l=l+1;
                r=r-1;
                continue;
            }
            // left sorted
            if(nums[l]<=nums[mid]){
                if(nums[mid]>=target && nums[l]<=target)r=mid-1;
                else l=mid+1;
            }
            // right sorted
            else {
                if(nums[r]>=target && nums[mid]<=target)l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};