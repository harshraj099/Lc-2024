class Solution {
public:
    int findMaxK(vector<int>& nums) {
       set<int>s;
       sort(nums.begin(),nums.end());

        for(auto it:nums){
           s.insert(it);
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>0 && s.find(-nums[i])!=s.end())return nums[i];
            if(nums[i]<0)break; 
        }
        return -1;
    }
};