class Solution {
public:
   int f(int idx1,int idx2,string &s, string &t,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        // if matches on idx
        int take=0;
        if(s[idx1]==t[idx2]) take=1+f(idx1-1,idx2-1,s,t,dp);
    //     or
    //   if(text1[idx1]==text2[idx2])  return 1+f(idx1-1,idx2-1,text1,text2,dp);
        
        // not matches
        int nt=0;
        if(s[idx1]!=t[idx2])  nt=0+max(f(idx1-1,idx2,s,t,dp),f(idx1,idx2-1,s,t,dp));
       //or
//return  dp[idx1][idx2]=max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));

        return dp[idx1][idx2]=take+nt;
    }
    int minDistance(string word1, string word2) {
          int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      int r=  f(n-1,m-1,word1,word2,dp);
      int ans=n-r+m-r;
      return ans;
    }
};