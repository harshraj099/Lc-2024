class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty() && s[i]=='(' | s[i]==')')st.push({s[i],i});
           else if(s[i]==')'&& st.top().first=='(')st.pop();
            else if(s[i]=='(' | s[i]==')'){st.push({s[i],i});
            }
        }
        // cout<<"hi";
        int cnt=0;
        while(!st.empty()){
            int ind=st.top().second;
            st.pop();
            s.erase(s.begin()+ind,s.begin()+ind+1);
            // cout<<s<<endl;
        }
        return s;
    }
};