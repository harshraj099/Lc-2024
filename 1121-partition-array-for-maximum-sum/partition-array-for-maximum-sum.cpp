class Solution {
public:
     int f(int i,int n,vector<int>& arr, int k,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=-1e9;
        int len=0,max_ele=-1;;   
        for(int ind=i;ind<n && ind<i+k;ind++){
        len++;
        max_ele=max(max_ele,arr[ind]);
        int sum=max_ele*len+f(ind+1,n,arr,k,dp);
          maxi=max(maxi,sum);
        
        }
        return dp[i]= maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
            vector<int>dp(n,-1);
       return f(0,n,arr,k,dp);
    }
};


