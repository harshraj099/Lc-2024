class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int ptr=-2;
        for(int i=0;i<s.size();i++){
            if(i-2>=0 && s[i-2]==s[i] && s[i-1]==s[i]){
                continue;
            }
            else{ ans+=s[i];
            // ptr=i;
            }
        }
        return ans;
    }
};