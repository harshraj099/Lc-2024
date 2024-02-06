class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>m;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            // if(m.find(s)!=m.end()){
            //     m[s].push_back(i);
            // }
              m[s].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto x:m){
            vector<string>st;
            for(auto it:x.second){
                st.push_back(strs[it]);
            }
            ans.push_back(st);
        }
        return ans;
    }
};