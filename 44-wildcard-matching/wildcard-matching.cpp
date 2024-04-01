class Solution {
public:
       int f(int i,int j,string &s, string &p,vector<vector<int>>&dp){
        if(i<0 && j<0)return 1;   //true
        if(i>=0 && j<0)return 0;   //false
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]!='*')return 0;
                j--;
            }
            return 1;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        // matching condition
        int take=0;
         int not_take=0;
      if(s[i]==p[j] || p[j]=='?')  take= f(i-1,j-1,s,p,dp);
    // or
    // if(s[i]==p[j])  return dp[i][j]=0+f(i-1,j-1,s,p,dp);
        
        // not matching 
         
   else if(p[j]=='*') not_take =f(i-1,j,s,p,dp)|f(i,j-1,s,p,dp);
   else return false;
        return dp[i][j]=take | not_take ;
    // or
//    return dp[i][j]= 1+min(f(i,j-1,s,p,dp),     //insertion
//                           min (f(i-1,j,s,p,dp),    //deletion
//                            f(i-1,j-1,s,p,dp)));  // replace
    }
    bool isMatch(string s, string p) {
                 int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};