class Solution {
public:
vector<vector<int>>vec;
   void getsubset(int idx,vector<int>& nums,vector<int>&v){
        if(idx==nums.size()){
            vec.push_back(v);
            return;
        }
        // take
        v.push_back(nums[idx]);
        getsubset(idx+1,nums,v);
        v.pop_back();
        //not take
       getsubset(idx+1,nums,v);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>v;
        getsubset(0,nums,v);
        int sum=0;
        for(auto it:vec){
            int xr=0;
            for(auto i:it){
                xr=xr^i;
            }
            sum+=xr;
        }

        return sum;
    }
};