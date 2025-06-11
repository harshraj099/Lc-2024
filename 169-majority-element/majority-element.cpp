class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int var=nums[0];
        int ct=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==var){
                ct++;
            }
            else {
                if(ct>0){
                    ct--;
                }
                else {
                    var=nums[i];
                    ct=1;
                }
            }
        }

        return var;
    }
};