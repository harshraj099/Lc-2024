class Solution {
public:

//  TLE 

    // bool check(int prev,string s1,vector<string>& words){
    //     if(prev==-1)return true;
    //     string s2=words[prev];
       
    // if(s1.size() != s2.size() + 1) return false;
    
    // int i = 0;
    // int j = 0;
    
    // while(i < s1.size()){
    //     if(j < s2.size() && s1[i] == s2[j]){
    //         i ++;
    //         j ++;
    //     }
    //     else i ++;
    // }
    // if(i == s1.size() && j == s2.size()) return true;
    // else return false; 
    // }
    // int f(int idx,int prev,vector<string>& words,int n,vector<vector<int>>&dp){
    //     if(idx==n)return 0;

    //     if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
    //     // take
    //     int take=0;
    //     if(check(prev,words[idx],words))take=1+f(idx+1,idx,words,n,dp);

    //     // leave
    //     int leave=f(idx+1,prev,words,n,dp);

    //     return  dp[idx][prev+1]=max(take,leave);
    // }

    // NO TLE
     bool check(string s2,string s1){
     if(s1.size() != s2.size() + 1) return false;
    
    int i = 0;
    int j = 0;
    
    while(i < s1.size()){
        if(j < s2.size() && s1[i] == s2[j]){
            i ++;
            j ++;
        }
        else i ++;
    }
    if(i == s1.size() && j == s2.size()) return true;
    else return false; 
     }


    static bool sortsize(string &a, string  &b){
        return b.size()>a.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),sortsize);
        // string prev="";
        int n=words.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //    return f(0,-1,words,n,dp); 

        // no TLE
        vector<int>idx(n);
        vector<int>dp(n,1);
        int lastIdx;
        int maxi=0;
        for(int i=0;i<n;i++){
            idx[i]=i;
            for(int j=0;j<i;j++){
                if(check(words[j],words[i]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIdx=i;
            }
        }

        int ct=1;
        while(idx[lastIdx]!=lastIdx){
            ct++;
            lastIdx=idx[lastIdx];
        }

        return ct;
    }
};