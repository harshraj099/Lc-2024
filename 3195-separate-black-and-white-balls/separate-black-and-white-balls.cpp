class Solution {
public:
    long long minimumSteps(string s) {
        long long zeros=0;
         long long n=s.size();
         long long ct=0;
     for(int i=n-1;i>=0;i--){
        if(s[i]=='0')zeros++;
        if(s[i]=='1')ct+=zeros;
     }

        return ct;
    }
};