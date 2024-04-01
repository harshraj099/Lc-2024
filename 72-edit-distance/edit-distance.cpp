class Solution {
public:
    int f(int i,int j,string &s, string &t,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1; 

        if(dp[i][j]!=-1)return dp[i][j];
        //if matches on idx
        int take=1e5;
      if(s[i]==t[j])  take= f(i-1,j-1,s,t,dp);
    // or
    // if(s[i]==t[j])  return dp[i][j]=0+f(i-1,j-1,s,t,dp);
        
        // not matches
    int not_take =1+min(f(i,j-1,s,t,dp),     //insertion
                          min (f(i-1,j,s,t,dp),    //deletion
                           f(i-1,j-1,s,t,dp)));  // replace
        return dp[i][j]=min(take,not_take);
    // or
//    return dp[i][j]= 1+min(f(i,j-1,s,t,dp),     //insertion
//                           min (f(i-1,j,s,t,dp),    //deletion
//                            f(i-1,j-1,s,t,dp)));  // replace
    }
    int minDistance(string word1, string word2) {
        //            int n=word1.size();
        // int m=word2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,word1,word2,dp);

        // tabulation
            int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // base case
        //  if(i<=0)return j;
        // if(j<=0)return i;
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
        if(word1[i-1]==word2[j-1]) dp[i][j]= dp[i-1][j-1];
               else  dp[i][j]= 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};