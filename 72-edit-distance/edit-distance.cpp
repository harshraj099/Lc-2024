class Solution {
public:
     int f(int i,int j,int n,int m,string &text1, string &text2, vector<vector<int>>&dp){
        if(i>=n)return m-j;
        if(j>=m)return n-i;

        if(dp[i][j]!=-1)return dp[i][j];
        // take
        int take=1e9,state=1e9;
        if(text1[i]==text2[j])take=f(i+1,j+1,n,m,text1,text2,dp);
        else state=min(1+f(i,j+1,n,m,text1,text2,dp),//insert
                        min(1+f(i+1,j,n,m,text1,text2,dp),//delete
                        1+f(i+1,j+1,n,m,text1,text2,dp)));//replace

        return  dp[i][j]=min(take,state);
    }
    int minDistance(string word1, string word2) {
         int n=word1.size();
        int m=word2.size();;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,word1,word2,dp);
    }
};