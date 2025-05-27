class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        // prefix[0]=nums[0];
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int ct=0;
        for(int i=0;i<n;i++){
            int l=0;
            while(l<=i){
                if(prefix[i+1]-prefix[l]==goal){
                    ct++;
                }
                l++;
            }
        }
        return ct;
    }
};