class Solution {
public:
    string f(int n){
        if(n==1)return "1";
        string  s=f(n-1);

        string t="";
        for(int i=0;i<s.size();){
            int j=i+1;
            while(j<s.size() && s[j]==s[i]){
                j++;
            }
            t+=to_string(j-i)+s[i];
            i=j;
        }

        return t;
    }
    string countAndSay(int n) {
        return f(n);
    }
};