class Solution {
public:
    bool checkValidString(string s) {
          stack<pair<char,int>>st,sttt;
          queue<pair<char,int>>star;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty() && s[i]=='(' | s[i]==')')st.push({s[i],i});
           else if(s[i]==')'&& st.top().first=='(')st.pop();
            else if(s[i]=='(' | s[i]==')')st.push({s[i],i});
              else star.push({s[i],i});
        }
        // cout<<st.size();
        while(!st.empty()){
             int ind=st.top().second;
            char ch=st.top().first;
            sttt.push({ch,ind});
            st.pop();
        }
        while(!sttt.empty() && !star.empty()){
            int ind=sttt.top().second;
            char ch=sttt.top().first;
            int i=star.front().second;
            // cout<<i<<" "<<ind; 
            if(i<ind && ch==')'){
             sttt.pop();
             star.pop();
            }
            else if(i>ind && ch=='('){
             sttt.pop();
             star.pop();
            }
              else if(i<ind && ch=='('){
             star.pop();
            }
            else break;
        }
        if(sttt.empty())return true;
        return false;
        
    }
};