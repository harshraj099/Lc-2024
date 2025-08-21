class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>>res;
         for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;  // to avoid repeat
            int l=i+1,r=n-1;
            while(l<r){
                if((nums[l]+nums[r]+nums[i])==0){
                    res.push_back({{nums[i],nums[l],nums[r]}});
                    l++;
                    r--;
                    // skip duplicates
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(l<r && nums[r]==nums[r+1])r--;
                }
                else if((nums[l]+nums[r]+nums[i])<0){
                    l++;
                }
                else r--;
            }
         }
         return res;
    }
};