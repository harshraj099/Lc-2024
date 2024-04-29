class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int p=0;
        for(int i=0;i<nums.size();i++){
            p=p^nums[i];
        }
        p=p^k;
        int ct=0;
        while(p>0){
          if(p%2==1)ct++;
          p=p>>1;  
        }
        return ct;
    }
};