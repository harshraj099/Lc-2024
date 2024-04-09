class Solution {
public:
    int f(int i,int j,string &s){
        while(i>=0 && j<s.size() &&  s[i]==s[j]){
                i--;
                j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int l=0,r=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int len1=f(i,i,s);
            int len2=f(i,i+1,s);
            int len=max(len1,len2);
            if(len>maxi){
                maxi=len;
             l=i-(len-1)/2;
             r=i+len/2;
            }
        }
        // cout<<l<<" "<<r;
        return s.substr(l,r-l+1);
    }
};