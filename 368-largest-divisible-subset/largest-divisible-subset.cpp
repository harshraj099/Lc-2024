
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
           vector<int>dp(n,1),hash(n);
           sort(nums.begin(),nums.end());
      int  last_idx=0;
       int maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last_idx=i;
            }
        }
        vector<int>ans;
        while(hash[last_idx]!=last_idx){        // jab tak ki last idx ==hash[last idx ] nahi ho jata
            ans.push_back(nums[last_idx]);
            last_idx=hash[last_idx];
        }
         ans.push_back(nums[last_idx]);
         
         reverse(ans.begin(),ans.end());
         
         return ans;
    }
};



