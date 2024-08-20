class Solution {
public:
        int f(int i,int n,vector<int>& arr, int k,vector<int>&dp){
            if(i>=n)return 0;
            if(dp[i]!=-1)return dp[i];

            int ans=0,ele=0;
            for(int ind=i;ind<min(n,i+k);ind++){
                 ele=max(ele,arr[ind]);
                int sum=ele*(ind-i+1)+f(ind+1,n,arr,k,dp);
                ans=max(ans,sum);
            }
            return dp[i]=ans;
        }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
      return  f(0,n,arr,k,dp);
    }
};