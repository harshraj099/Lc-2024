class Solution {
public:
    int f(int idx,vector<int>& nums,int xr){
        if(idx==nums.size()) return xr;

        // take
      int take= f(idx+1,nums,xr^nums[idx]);

        // leave
      int leave=  f(idx+1,nums,xr);

      return take+leave;

    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        return f(0,nums,0);
    }
};