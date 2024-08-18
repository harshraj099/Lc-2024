class Solution {
public:int f(int ind,int n,vector<int>& prices,vector< vector<vector<int>>>&dp,int fl,int bond){
    if(ind==n || bond==2)return 0;
    if(dp[ind][fl][bond]!=-1)return dp[ind][fl][bond];
    // buy
    int profit=0;
    if(!fl)profit=max(-prices[ind]+f(ind+1,n,prices,dp,!fl,bond),f(ind+1,n,prices,dp,fl,bond));
    // sell
    if(fl)profit=max(prices[ind]+f(ind+1,n,prices,dp,!fl,bond+1),f(ind+1,n,prices,dp,fl,bond));

     return  dp[ind][fl][bond]=profit;
}
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
    //    vector< vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //    return f(0,n,prices,dp,0,0);

        // tabulation
       vector< vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
                  int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int fl=0;fl<=1;fl++){
                for(int limit=1;limit>=0;limit--){
                  //buy
    if(!fl) profit=max(-prices[i]+dp[i+1][!fl][limit],dp[i+1][fl][limit]);
    // sell
    if(fl)profit=max(prices[i]+dp[i+1][!fl][limit+1],dp[i+1][fl][limit]);

       dp[i][fl][limit]=profit;
    //    cout<<dp[i][fl][limit]<<endl;   
                }
            }
        }
        return dp[0][0][0];
    }
};