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
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
          int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return  f(n-1,m-1,s,t,dp);
    //      string ans="";
    //     int i=n-1,j=m-1;
    //     while(i>=0 && j>=0){
    //       if(s[i]==t[j]){
    //           ans+=s[i];
    //           i--;
    //           j--;
    //       }
    //       else {
    //           if(dp[i][j-1]>dp[i-1][j]){
    //               j--;
    //           }
    //           else i--;
         
    //       }
    //     }
    //     // reverse(ans.begin(),ans.end());
    //    return ans;
    }
};