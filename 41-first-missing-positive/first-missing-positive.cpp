class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                continue;}
          else{
            while(i<nums.size()){
                if(nums[i]<k){i++;
                    continue;}
                if(nums[i]!=k)return k;
                k++;
                i++;
            }
            break;
          }
            }
        return k;
    }
};