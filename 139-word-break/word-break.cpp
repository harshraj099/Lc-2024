class Solution {
public:
     bool f(int i,string s,int n, vector<string>& wordDict,vector<int>&dp){
        if(i==n){
            return true;
        }
        if(dp[i]!=-1)return dp[i];
        for(int idx=i;idx<n;idx++){
            // if(i!=idx && s[i]==s[idx])continue;
            string st = s.substr(i, idx - i + 1);
            if(distance(wordDict.begin(),find(wordDict.begin(),wordDict.end(),st))<wordDict.size()){
            if(f(idx+1,s,n,wordDict,dp))return dp[idx]=true;
            }
        } 

        return dp[i]= false; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n=s.size();
         vector<int>dp(n,-1);
       return f(0,s,n,wordDict,dp); 
    }
};