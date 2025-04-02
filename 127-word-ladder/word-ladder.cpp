class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(auto it:wordList){
            s.insert(it);
        }

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string st=q.front().first;
            int times=q.front().second;
            q.pop();
            if(st==endWord)return times;
            for(int i=0;i<st.size();i++){
                string temp=st;
              for(int j=0;j<26;j++){
                temp[i]='a'+j;
                if(s.find(temp)!=s.end()){
                    q.push({temp,times+1});
                    s.erase(temp);
                }
            }
            }
           
        }

        return 0;
    }
};