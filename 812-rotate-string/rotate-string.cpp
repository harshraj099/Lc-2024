class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return 0;
        string st=s+s;
        if(st.find(goal)!=string::npos)return 1;
        return 0;
    }
};