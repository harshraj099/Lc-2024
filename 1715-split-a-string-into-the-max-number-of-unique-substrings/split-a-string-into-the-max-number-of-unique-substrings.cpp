class Solution {
public:
    int f(int i,string temp,string &s,set<string>st){
        if(i==s.size())return 0;
        temp+=s[i];
        // take
        int take=0;
        if(st.empty() || st.find(temp)==st.end()){
            st.insert(temp);
            take=1+f(i+1,"",s,st);
            st.erase(temp);
        }

        // not take
       int nt=f(i+1,temp,s,st);

        return max(take,nt);
    }
    int maxUniqueSplit(string s) {
        set<string>st;
      return  f(0,"",s,st);
    }
};