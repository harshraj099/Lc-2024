class Solution {
public:
    int minimumDeletions(string s) {
        int ct=0;
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='b'&& s[i]=='a'){
                    ct++;
                    st.pop();
                }
                else st.push(s[i]);
        }
       return ct;
    }
};