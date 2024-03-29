class Solution {
public:
    	 int f(int idx1,int idx2,string &s, string &t,vector<vector<int>>&dp){
        if(idx1<=0 || idx2<=0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        // if matches on idx
      if(s[idx1-1]==t[idx2-1])  return dp[idx1][idx2]= 1+f(idx1-1,idx2-1,s,t,dp);
        
        // not matches
       return  dp[idx1][idx2]=max(f(idx1-1,idx2,s,t,dp),f(idx1,idx2-1,s,t,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
            int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    f(n,m,str1,str2,dp);
        //      for(auto it:dp){
        //      for(auto i:it)cout<<i<<" ";
        //      cout<<endl;
        //  }
         string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
          if(str1[i-1]==str2[j-1]){
              ans+=str1[i-1];
              i--;
              j--;
          }
          else {
              if(dp[i][j-1]>dp[i-1][j]){
                ans+=str2[j-1];
                  j--;
              }
              else {
                ans+=str1[i-1];
                i--;
                }
         
          }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
         while(j>0){
            ans+=str2[j-1];
            j--;
        }
             reverse(ans.begin(),ans.end());
            return ans;
    }
};