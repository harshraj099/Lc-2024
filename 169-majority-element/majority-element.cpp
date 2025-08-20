class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int var=nums[0];
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==var){
                ct++;
            }
            else {
                ct--;
                if(ct==0) {
                    var=nums[i];
                    ct=1;
                }
            }
        }

        return var;
    }
};