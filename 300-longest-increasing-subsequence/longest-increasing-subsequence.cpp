class Solution {
public:
        int f(int i,int prev_idx,vector<int>& a, vector<vector<int>>&dp,int n){
            if(i==n)return 0;

            if(dp[i][prev_idx+1]!=-1)return dp[i][prev_idx+1];
            //take
            int take=0;
            // or
            // int length=0;
            if(prev_idx==-1 || a[i]>a[prev_idx]){
                take=1+f(i+1,i,a,dp,n);
                //or
                // length=1+f(i+1,i,a,dp,n);

            }
            // not take 
            int not_take=0+f(i+1,prev_idx,a,dp,n);

            return dp[i][prev_idx+1]=max(take,not_take);

                //or
            // return dp[i][prev_idx+1]=max(length,f(i+1,prev_idx,a,dp,n));

        }
    int lengthOfLIS(vector<int>& a) {
        // int n=a.size();
        //initialise the prev idx from -1
        //therefore we require a dp of n+1 as prev idx from -1 to n-1 
        // inc the idx by 1 -> 0 to n
        // so n*n+1 dp
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //    return f(0,-1,a,dp,n);

       //tabulation
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // basecase
        // for(int j=0;j<n+1;j++)dp[0][j]=0;
        // no need already 0

        for(int i=n-1;i>=0;i--){
            for(int prev_idx=i-1;prev_idx>=-1;prev_idx--){
                 int take=0;
        if(prev_idx==-1 || a[i]>a[prev_idx]){
                take=1+dp[i+1][i+1];
        }
                int  not_take=0+dp[i+1][prev_idx+1];
             dp[i][prev_idx+1]=max(take,not_take);
            }
        }
    //      for(int ind = n-1; ind>=0; ind --){
    //     for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
    //         int notTake = 0 + dp[ind+1][prev_index +1];
    
    //         int take = 0;
    
    //         if(prev_index == -1 || a[ind] > a[prev_index]){
                
    //             take = 1 + dp[ind+1][ind+1];
    //         }
    
    //         dp[ind][prev_index+1] = max(notTake,take);
            
    //     }
    // }
        return dp[0][0];
    }
};