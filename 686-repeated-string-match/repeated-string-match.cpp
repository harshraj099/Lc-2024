class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b)return 1;
        int ct=1;
        string repeat=a;
        if(repeat.find(b)!=string::npos){
               return ct;
            }
        while(repeat.size()<b.size()){
            repeat+=a;
            ct++;
            if(repeat.find(b)!=string::npos){
               return ct;
            }
        }
         repeat+=a;
            ct++;
        if(repeat.find(b)!=string::npos){
               return ct;
            }
        return -1;
    }
};