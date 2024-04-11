class Solution {
public:
    int f(int idx,int n,string &s,vector<int>&dp){
        if(s[0]=='0')return 0;
        if(idx>=n)return 1;
        if(idx==n-1){
            if(s[idx]=='0')return 0;
            return 1;
        }
        if(dp[idx]!=-1)return dp[idx];
        string temp="";
        int ways=0;
        for(int i=idx;i<n;i++){
            temp+=s[i];
            if(temp[0]!='0' && stoi(temp)<=26)ways+=f(i+1,n,s,dp);
            else break;
        }
        return dp[idx]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
       return f(0,n,s,dp);
    }
};