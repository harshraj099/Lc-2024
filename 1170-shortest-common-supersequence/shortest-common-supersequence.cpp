class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
         // tabulation
         int n=str1.size(),m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           int take=0,not_take=0;
        if(str1[i-1]==str2[j-1])take=1+dp[i-1][j-1];
        else not_take=max(dp[i-1][j],dp[i][j-1]);

         dp[i][j]=max(take,not_take);
            }
        }
        string ans="";
        int l=n,r=m;
        while(l>0 && r>0){
            if(str1[l-1]==str2[r-1]){
                ans+=str1[l-1];
                l--;
                r--;
            }
            else if(dp[l-1][r]>dp[l][r-1]){
                ans+=str1[l-1];
                l--;
            }
            else {
                ans+=str2[r-1];
                r--;
                }
        }
       while(l>0){
        ans+=str1[l-1];
        l--;
       }
       while(r>0){
        ans+=str2[r-1];
        r--;
       }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};