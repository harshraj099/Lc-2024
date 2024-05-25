class Solution {
public:
    void f(int idx,string s,set<string>st, vector<string>&output,vector<string>&v){
        if(idx==s.size()){
            string store="";
            for(int i=0;i<v.size();i++){
                store+=v[i];
               if(i!=v.size()-1)store+=" ";
            }
            output.push_back(store);
            return;
        }
        string temp="";
        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                 //take
              v.push_back(temp);
              f(i+1,s,st,output,v);
              v.pop_back();
            }
        }
            return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
         vector<string>v;
        for(auto it:wordDict)st.insert(it);

        vector<string>output;
        f(0,s,st,output,v);
        return output;
    }
};