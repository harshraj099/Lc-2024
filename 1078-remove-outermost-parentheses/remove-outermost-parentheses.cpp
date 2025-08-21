class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(balance>0)ans+=s[i];
                balance++;
            }
            else{
                balance--;
                if(balance>0)ans+=s[i];
            }
        }
        return ans;

        // "(()())(())(()(()))"
        // dry run this to know condition of balance in above
    }
};