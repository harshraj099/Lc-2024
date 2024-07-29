class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=1e6;
        int mini=1e6;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            for(auto it:nums)sum+=ceil(double(it)/mid);
            if(sum<=threshold){
                mini=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return mini;
    }
};