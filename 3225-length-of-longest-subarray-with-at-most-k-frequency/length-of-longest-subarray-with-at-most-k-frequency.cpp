class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>m;
        int i;
        int maxi=0,temp=0;
        for( i=0;i<nums.size();i++){

                m[nums[i]]++;
            if( m[nums[i]]>k){
                while(m[nums[temp]]!=m[nums[i]]){
                m[nums[temp]]--;
                temp++;
                }
                m[nums[temp]]--;
                temp++;
            }
            maxi=max(maxi,i-temp+1);
        }
          
      
        return maxi;
    }
};