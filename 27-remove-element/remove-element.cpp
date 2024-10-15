class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ct=0;
        int i=0;
        int n=nums.size();
        while(i<nums.size())
        {
            if(nums[i]==val){
                ct++;
                nums.erase(nums.begin()+i);

            }
          else  i++;
        }
        return n-ct;
    }
};