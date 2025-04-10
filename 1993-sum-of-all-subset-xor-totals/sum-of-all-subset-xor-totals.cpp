class Solution {
public:
    void f(int idx,int &sum,vector<int>& nums,int xr){
        if(idx==nums.size()){
            sum+=xr;
            return;
        }

        // take
        f(idx+1,sum,nums,xr^nums[idx]);

        // leave
        f(idx+1,sum,nums,xr);

    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        f(0,sum,nums,0);

        return sum;
    }
};