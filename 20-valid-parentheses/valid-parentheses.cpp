class Solution {
public:
    bool isValid(string s) {
       stack<char>ch;
        for(int i=0;i<s.size();i++){
           if(s[i]=='(' || s[i]=='{' || s[i]=='[' ) ch.push(s[i]);
          else if(ch.empty())return false;
           else if(ch.top()=='(' && s[i]==')')ch.pop();
           else if(ch.top()=='{' && s[i]=='}')ch.pop();
           else if(ch.top()=='[' && s[i]==']')ch.pop();
           else return false;
        }
        if(ch.size()==0)return true;
        else return false;
    }
};