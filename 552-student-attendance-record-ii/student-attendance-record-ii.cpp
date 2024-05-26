class Solution {
public:
    const int mod=1e9+7;
    int f(int idx,vector<vector<vector<int>>>&dp,int countl,int counta){
        if(idx==0){
            return 1;
        }

            if(dp[idx][countl][counta]!=-1)return dp[idx][countl][counta];

            int res=0;
        // present
       res= (res+f(idx-1,dp,0,counta))%mod;

        // late
      if(countl<2) res= (res+f(idx-1,dp,countl+1,counta))%mod;

        //absent
        if(counta<1) res= (res+f(idx-1,dp,0,counta+1))%mod;


        return dp[idx][countl][counta]=res;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));

      return  f(n,dp,0,0);
    }
};