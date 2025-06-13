class Solution {
public:
    int myAtoi(string s) {
        // just read the digit
        int sign=1;
        long long res=0;

        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ')i++;
        if(i==n)return 0;

        if(s[i]=='-'){sign=-1;
        i++;}
        else if(s[i]=='+')i++;
        // read number
        while(i<n && isdigit(s[i])){
            res=res*10+(s[i]-'0');

            if(sign*res>INT_MAX)return INT_MAX;
            if(sign*res<INT_MIN)return INT_MIN;
            i++;
        }

        return res*sign;
    }
};