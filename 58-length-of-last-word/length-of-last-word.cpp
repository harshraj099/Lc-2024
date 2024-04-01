class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ')continue;
            else {
               while(i>=0 && s[i]!=' '){
                length+=1;
                i--;
               }
               break;
            }
        }
        return length;
    }
};