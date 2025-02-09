class Solution {
public:
        int f(int num,int size,int n,vector<int>&dp){
            if(num>size || n<0)return 1e9;
            if(n==0)return 0;

            if(dp[n]!=-1)return dp[n];
            // take
            int take=1+f(num,size,n-num*num,dp);

            // leave
            int leave=f(num+1,size,n,dp);

            return  dp[n]=min(take,leave);
        }
    int numSquares(int n) {
    //     vector<int>dp(n+1,-1);
    //    return f(1,sqrt(n),n,dp);

    //    tabulation
        vector<int>dp(n+1,1e9);
            dp[0]=0;
            for(int i=1;i<=n;i++){
                  for(int num=1;num<sqrt(n)+1;num++){
                    
                  if(i-num*num>=0)dp[i]=min(dp[i],1+dp[i-num*num]);
                //   cout<<i<<"->"<<dp[i]<<endl;
            }
        }
        return dp[n];
    }
};