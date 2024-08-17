class Solution {
public:
    int f(int i,int j,int n,int m,string &s, string &p, vector<vector<int>>&dp){
        if(i>=n && j>=m)return 1;
        if(i>=n && j<m){
            while(j<m){
                if(p[j]!='*')return 0;
                j++;
            }
            return 1;
        }
        if(i<n && j>=m)return 0;


        if(dp[i][j]!=-1)return dp[i][j];
        
       int take=0,not_take=0;
        if(s[i]==p[j] | p[j]=='?')take=f(i+1,j+1,n,m,s,p,dp);
        else if(p[j]=='*') not_take=f(i+1,j,n,m,s,p,dp)|f(i,j+1,n,m,s,p,dp);  //some characters or zero characters
        else return 0;

        return  dp[i][j]=take|not_take;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
       int m=p.size();;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,s,p,dp);
    }
};