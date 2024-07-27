class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // dutch national fllag algorithm
        // left me 0 hogi , mid me 1  and right me 2

        int left=0,mid=0,right=nums.size()-1;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid]==1)mid++;

            else {
                swap(nums[mid],nums[right]);
                right--;
            }
        }
    }
};