class Solution {
public:
    void f(int i,vector<int>&v,vector<int>&nums,vector<vector<int>>&res,int n){
        if(i==n){
            res.push_back(v);
            return;
        }

        // take
        v.push_back(nums[i]);
        f(i+1,v,nums,res,n);
        v.pop_back();

        // leave
        f(i+1,v,nums,res,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        vector<int>v;
        f(0,v,nums,res,n);

        return res;
    }
};