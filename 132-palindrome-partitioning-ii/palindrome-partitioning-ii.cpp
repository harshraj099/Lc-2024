class Solution {
public:
        // int mini=1e9;  wrong because if once mini is gets value it cant be changed 
    bool ispalindrome(string &temp){
        int l=0,r=temp.size()-1;
        while(l<r){
            if(temp[l]!=temp[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int f(int i,int n,string &s, vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        int mini=1e9;   // here mini is redefined again and again so dont worry 1 wont be
                        //  returned every time. after all possibility is compiled and minimum is 
                        // returned from all possibility a final minimun will be returned at the end 
                        //  and correct ans is returned.
        for(int ind=i;ind<n;ind++){
        temp+=s[ind];
        if(ispalindrome(temp)){
          int  cut=1+ f(ind+1,n,s,dp);
              mini=min(mini,cut);
        }
        }
        return dp[i]= mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
       return f(0,n,s,dp)-1;
    }
};