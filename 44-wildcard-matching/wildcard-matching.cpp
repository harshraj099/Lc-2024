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
    //     int take=0;
    //      int not_take=0;
    //   if(s[i]==p[j] || p[j]=='?')  take= f(i-1,j-1,s,p,dp);
    // or
      if(s[i]==p[j] || p[j]=='?')  return dp[i][j]=f(i-1,j-1,s,p,dp);
        
        // not matching 
         
//    else if(p[j]=='*') not_take =f(i-1,j,s,p,dp)|f(i,j-1,s,p,dp);
//    else return false;
//         return dp[i][j]=take | not_take ;
    // or
 else if(p[j]=='*')  return dp[i][j]= f(i-1,j,s,p,dp)|f(i,j-1,s,p,dp);
       else return false;                    
    }
    bool isMatch(string s, string p) {
        //          int n=s.size();
        // int m=p.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,s,p,dp);

        //tabulation
                int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // basecase
        dp[0][0]=1;
        for(int i=1;i<=n;i++)dp[i][0]=0; //if(j==0)
         for(int j=1;j<=m;j++){  
            int fl=1;                   
            for(int idx=1;idx<=j;idx++){
                if(p[idx-1]!='*') {fl=0;
                break;}
            }
         dp[0][j]=fl;
         if(!fl)break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
      if(s[i-1]==p[j-1] || p[j-1]=='?')   dp[i][j]=dp[i-1][j-1];
     else if(p[j-1]=='*') dp[i][j]= dp[i-1][j]|dp[i][j-1];
       else dp[i][j]=0; 
            }
        }
        return dp[n][m];
    }
};