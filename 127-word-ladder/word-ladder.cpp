class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>m;
        for(auto it:wordList)m.insert(it);
        queue<pair<int,string>>q;
        q.push({1,beginWord});
        set<string>vis;
        while(!q.empty()){
            auto [ct,word]=q.front();
            if(word==endWord)return ct;
            q.pop();
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(temp!=word && m.find(temp)!=m.end() &&vis.find(temp)==vis.end()){
                        vis.insert(temp);
                        q.push({ct+1,temp});
                    }
                }
            }
        }

        return 0;
    }
};