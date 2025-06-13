class Solution {
public:
    int romanToInt(string s) {
        map<char,int>symbol={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int res=symbol[s[0]];
        for(int i=1;i<s.size();i++){
            if(symbol[s[i-1]]<symbol[s[i]]){
                res-=2*(symbol[s[i-1]]);
                res+=(symbol[s[i]]);
            }
            else {
                res+=(symbol[s[i]]);
            }
        }

        return res;
    }
};