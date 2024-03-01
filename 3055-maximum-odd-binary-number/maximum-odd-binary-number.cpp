class Solution {
public:
    string maximumOddBinaryNumber(string s) {
       sort(s.begin(),s.end());
       reverse(s.begin(),s.end());
       for(int j=s.size()-1;j>=0;j--){
           if(s[j]=='1'){
               swap(s[s.size()-1],s[j]);
               break;
           }
       }
       return s;
    }
};