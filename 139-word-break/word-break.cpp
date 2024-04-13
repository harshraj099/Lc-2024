class Solution {
public:
    bool present(string &st,vector<string>& wordDict){
        for(auto it:wordDict)if(it==st)return true;
        
        return false;
    }
    bool f(int idx,string &s,vector<string>& wordDict,vector<int>&dp){
        if(idx>=s.size())return true;
        if(dp[idx]!=-1)return dp[idx];
        string st="";
        bool check=false;
        for(int i=idx;i<s.size();i++){
            st+=s[i];
            if(present(st,wordDict) && f(i+1,s,wordDict,dp))return dp[idx]=check=true;
        }
        return dp[idx]=check;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
         return f(0,s,wordDict,dp);  
    }
};