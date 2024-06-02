class Solution {
public:
    string clearStars(string s) {
        vector<int>ind;
        vector<int>v[26];
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                // cout<<s[i];
                v[s[i]-'a'].push_back(i);
            }
           else {
                for (int j = 0; j < 26; j++) {
                    if (!v[j].empty()) {
                        ind.push_back(v[j].back());
                        v[j].pop_back();
                        break;
                    }
                }
                    ind.push_back(i);
            }
        }
        sort(ind.begin(),ind.end());
        // for(auto it:ind)cout<<it<<" ";
        cout<<endl;
        string ans="";
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(idx<ind.size() && i==ind[idx])idx++;
            else ans+=s[i];
        }
        return ans;
    }
};