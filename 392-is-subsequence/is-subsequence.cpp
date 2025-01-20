class Solution {
public:
    bool isSubsequence(string s, string t) {\
        if(s.size()==0)return true;
        int ptr=0;
        for(int i=0;i<t.size();i++){
            if(s[ptr]==t[i]){
                ptr++;
            }
        if(ptr==s.size())return true;
        }
        return false;
    }
};