class Solution {
public:
     int f(int i,int j,int n,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n || j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==text2[j])take=1+f(i+1,j-1,n,text1,text2,dp);
        else not_take=max(f(i+1,j,n,text1,text2,dp),f(i,j-1,n,text1,text2,dp));

        return  dp[i][j]=max(take,not_take);
    }
    int longestPalindromeSubseq(string s) {
        // string temp=s;
        // reverse(s.begin(),s.end());
        // string t=s;
        // s=temp;

          int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
      return   f(0,n-1,n,s,s,dp);
  
    }
};