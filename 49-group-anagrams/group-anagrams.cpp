
class Solution {
public:
    string getSignature(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string ss="";
        for (int i = 0; i < 26; i++) {
           ss.append(count[i],i+'a');
        }
        return ss;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            groups[getSignature(s)].push_back(s);
        }

        for (const auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
