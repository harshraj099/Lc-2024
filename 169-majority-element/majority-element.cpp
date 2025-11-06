class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int ct=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majority)ct++;
            else{
                ct--;
                if(ct==0){
                    majority=nums[i];
                    ct=1;
                }
            }
        }
        return majority;
    }
};