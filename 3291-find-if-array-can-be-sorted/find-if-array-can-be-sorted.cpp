class Solution {
public:
    int setbit(int no){
            int bit=0;
            while(no>0){
                if((no&1)!=0)bit++;
               no= no>>1;
            }
            return bit;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();

            for(int i=n-1;i>=0;i--){
                for(int j=0;j<i;j++){
                 if(setbit(nums[j])==setbit(nums[j+1]) && nums[j]>nums[j+1])swap(nums[j],nums[j+1]); 
                }
            }

            for(int i=1;i<n;i++){
                if(nums[i-1]>nums[i])return false;
            }
        
        return true;
    }
};