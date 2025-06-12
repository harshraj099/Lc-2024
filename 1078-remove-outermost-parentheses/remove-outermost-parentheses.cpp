class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int ind=0;
        string ans="";
        int ct=0;
        while(ind<s.size()){
           if(s[ind]==')'){
                ct--;
                st.push(s[ind]);
                if(ct==0){
                    st.pop();
                    string temp="";
                    while(st.size()>1){
                        temp+=st.top();
                        st.pop();
                    }
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    st.pop();
                }
            }
            else {
                st.push(s[ind]);
                ct++;
            }
            ind++;
        }

        return ans;
    }
};