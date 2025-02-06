class Solution {
public:

    bool f(int i,int j,int k,int n1,int n2,int n3,string s1, string s2, string s3, vector<vector<int>>&dp){
        if(k==n3)return true;

        if( dp[i][j]!=-1)return dp[i][j];
        
        bool t1=false,t2=false;
        if(i<n1 && s1[i]==s3[k]){
            // if(f(i+1,j,k+1,n1,n2,n3,s1,s2,s3))return true;
            t1=f(i+1,j,k+1,n1,n2,n3,s1,s2,s3,dp);
        }
        if(j<n2 && s2[j]==s3[k]){
            // if(f(i,j+1,k+1,n1,n2,n3,s1,s2,s3))return true;
            t2=f(i,j+1,k+1,n1,n2,n3,s1,s2,s3,dp);
        }

        return dp[i][j]=t1|t2;
        // return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n3<n1+n2 || n3>n1+n2)return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
       return f(0,0,0,n1,n2,n3,s1,s2,s3,dp);
    }
};