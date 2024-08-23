class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st;
        for(auto it:wordList)st.insert(it);
        while(!q.empty()){
            string ss=q.front().first;
            int add=q.front().second;
            // cout<<s<<endl;
            if(ss==endWord)return add;
            q.pop();
            int fl=0;
            for(int i=0;i<beginWord.size();i++){
                string s=ss;
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                         q.push({s,add+1});
                        st.erase(s);
                    }
                }
            }
        }
        return 0;
    }
};