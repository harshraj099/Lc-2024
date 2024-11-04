class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;

        int ct=0;
        while(ct<s.size()){
            if(s==goal)return true;
            s.push_back(s[0]);
            s.erase(s.begin());
            ct++;
        }
        return false;

    }
};