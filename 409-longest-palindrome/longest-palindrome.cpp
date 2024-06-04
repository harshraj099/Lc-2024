class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++)m[s[i]]++;

        int cnt=0;
        // int maxi=0;
        for(auto it:m){
            if(it.second%2==0)cnt+=it.second;
            if(it.second%2!=0)cnt+=(it.second-1);
            // if(it.second%2!=0)maxi=max(maxi,it.second);
            }

        cnt+=1;
        if(cnt>s.size())return s.size();
                return cnt;
    }
};