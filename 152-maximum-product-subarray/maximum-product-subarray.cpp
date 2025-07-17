class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mul=1,ml=1;
        int maxi=-11;
        for(int i=0;i<nums.size();i++){
            mul*=nums[i];
            ml*=nums[i];
            maxi=max({mul,maxi,ml});
            if(mul<=0)mul=1;
            if(ml==0)ml=1;
        }
        mul=1;
        ml=1;
        for(int i=nums.size()-1;i>=0;i--){
            mul*=nums[i];
            ml*=nums[i];
            maxi=max({mul,maxi,ml});
            if(mul<=0)mul=1;
            if(ml==0)ml=1;
        }
        return maxi;
    }
};