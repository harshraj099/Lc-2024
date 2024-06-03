class Solution {
public:
    int appendCharacters(string s, string t) {
       int cnt=0;
       int n=s.size();
       int ptr=0;
       int m=t.size();
       for(int i=0;i<n;i++){
        if(ptr<m && s[i]==t[ptr])ptr++;
        if(ptr==m)return 0;
       }
       cnt=m-ptr;
       return cnt;
    }
};