class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;

        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        
        vector<pair<int, char>> v;

        for(auto i:m)
            v.push_back({i.second, i.first});
        
        sort(v.rbegin(), v.rend());

        string ans="";

        for(auto i:v){
            ans.append(i.first,i.second);
        }

        return ans;
    }
};