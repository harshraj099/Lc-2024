class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        int mini=1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid] && nums[mid]<=nums[r]){
            mini=min(mini,nums[l]);
            r=mid-1;
            }
           else if(nums[l]>=nums[mid] && nums[mid]>=nums[r]){
            mini=min(mini,nums[r]);
            l=mid+1;
            }
            else if(nums[l]>=nums[r] && nums[mid]<=nums[r]){
            mini=min(mini,nums[mid]);
            r=mid-1;
            }
             else if(nums[l]>=nums[r] && nums[mid]>=nums[r]){
            mini=min(mini,nums[r]);
            l=mid+1;
            }  
        }
        return mini;
    }
};