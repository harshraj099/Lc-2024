class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        int ans=0;
        int l=0,r=0;
        while(l<=r && r<s.size()){
            m[s[r]]++;
            while(m['a'] && m['b'] && m['c']){
                ans+=s.size()-r;
                m[s[l]]--;
                l++;
            }
            r++;
        }

        return ans;
    }
};