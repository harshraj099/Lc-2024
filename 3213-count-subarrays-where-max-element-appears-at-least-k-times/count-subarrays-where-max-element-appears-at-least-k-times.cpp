class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // using sliding window
        long long n=nums.size();
        long long maxi=*max_element(nums.begin(),nums.end());
        long long l=0,r=0;
        long long ct=0;
        long long ans=0;
        while(l<=r && r<n){
            if(ct<k){
                if(nums[r]==maxi)ct++;
             if(ct<k) r++;
            }
            else {
              ans+=1+(n-1-r);
            //   cout<<ans<<endl;
                if(nums[l]==maxi){ct--;
                r++;}
                l++;
            }
        }
        return ans;
    }
};