class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ptr=nums.size()-1;
        long long sum=0;
        for(int i=0;i<nums.size()-1;i++)sum+=nums[i];

        while(sum>0 && (sum-nums[ptr])<=0){
            ptr--;
            sum-=nums[ptr];
        }
        if(sum==0)return -1;
        return sum+nums[ptr];
       
    }
};