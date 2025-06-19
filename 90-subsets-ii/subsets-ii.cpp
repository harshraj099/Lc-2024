class Solution {
public:
     void f(int i,vector<int>& nums,int n, vector<int>&v,vector<vector<int>>&res){
             res.push_back(v);
        
        for(int idx=i;idx<n;idx++){
            if(idx!=i && nums[idx]==nums[idx-1])continue;
        
            // take
            v.push_back(nums[idx]);
            f(idx+1,nums,n,v,res);
            v.pop_back();
        } 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>v;
        f(0,nums,n,v,res);
        return res;
    }
};