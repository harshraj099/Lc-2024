class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0;
        int len=INT_MAX;
        int sum=0;
        while(low<=high && high<=nums.size()){
            if(sum<target){
               if(high<nums.size())sum+=nums[high];
                high++;
                // cout<<high<<endl;
                }

            if(sum>=target){
               
                len=min(len,high-low);
                 cout<<low<<endl;
                 cout<<"hi"<<endl;
                sum-=nums[low];
                     low++;
            }
        }
        if(len==INT_MAX)return 0;
        return len;
    }
};