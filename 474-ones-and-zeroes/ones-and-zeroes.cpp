class Solution {
public:
    int dp[601][101][101];
    int f(int idx,int m ,int n,int size,vector<string>& strs){
        if(idx>=size) return 0;

          if(m>=0 && n>=0 && dp[idx][m][n]!=-1)return dp[idx][m][n];

        string s=strs[idx];
        int zeros=count(s.begin(),s.end(),'0');
        int ones=s.size()-zeros;

        // take 
        int take=0;
        if (m >= zeros && n >= ones) take=1+f(idx+1,m-zeros,n-ones,size,strs);

        // leave
        int leave=f(idx+1,m,n,size,strs);

        return dp[idx][m][n]=max(take,leave);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));  
       return f(0,m,n,strs.size(),strs);
    }
};