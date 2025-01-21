class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>m;
        stringstream str(s);
        string word;
        int i=0;
        set<string>st;
        while(str>>word){
            // cout<<pattern[i]<<endl;
            if(m.find(pattern[i])==m.end()){
              if(st.find(word)!=st.end())return false;
                m[pattern[i]]=word;
                  st.insert(word);
            }
            else{
                if(m[pattern[i]]!=word)return false;
            }
            i++;
        }
        if(i!=pattern.length())return false;
        return true;
    }
};