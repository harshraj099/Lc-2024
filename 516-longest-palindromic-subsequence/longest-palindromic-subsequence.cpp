class Solution {
public:
     int f(int i,int j,int n,int m,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=0,not_take=0;
        if(text1[i]==text2[j])take=1+f(i+1,j+1,n,m,text1,text2,dp);
        else not_take=max(f(i+1,j,n,m,text1,text2,dp),f(i,j+1,n,m,text1,text2,dp));

        return  dp[i][j]=max(take,not_take);
    }
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        string t=s;
        s=temp;

          int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      return   f(0,0,n,m,s,t,dp);
  
    }
};