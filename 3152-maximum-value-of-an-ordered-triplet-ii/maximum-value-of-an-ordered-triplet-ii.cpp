class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=nums[0],diff=0,ans=0;

        for(int i=1;i<nums.size();i++){
        ans=max(ans,diff*nums[i]);
         if(maxi-nums[i]>diff)diff=maxi-nums[i];
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }

        return ans;
    }
};