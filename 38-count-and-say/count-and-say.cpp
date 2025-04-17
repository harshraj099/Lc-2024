class Solution {
public:
    string f(int n){
        if(n==1)return "1";
        string s=f(n-1);
        string temp="";
        int l=0,r=0;
        while(r<s.size()){
            if(s[l]==s[r]){
                r++;
            }
            else{
                temp+=to_string(r-l)+s[l];
                l=r;
            }
        }
         temp+=to_string(r-l)+s[l];
         return temp;
    }
    string countAndSay(int n) {
        if(n==0)return "0";
        return f(n);
    }
};