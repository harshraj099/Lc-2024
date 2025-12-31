class Solution {
    public int search(int[] nums, int target) {
        int low=0,high=nums.length-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target)return mid;
            // left sorted
            else if(nums[low]<=nums[mid]){     // in left half sorted 
                if(nums[low]<=target && nums[mid]>=target)high=mid-1; // focus only on left part of left half
                else low=mid+1;
            }

            // right sorted
            else {
                 if(nums[mid]<=target && nums[high]>=target)low=mid+1; // focus only on right part of right half
                else high=mid-1;
            }
        }
        return -1;
    }
}