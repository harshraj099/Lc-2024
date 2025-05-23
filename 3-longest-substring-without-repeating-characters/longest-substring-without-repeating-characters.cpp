class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        map<char,int>m;
        int maxi=0;
        while(l<=r && r<s.size()){
            if(m[s[r]]==0){
                m[s[r]]=1;
                maxi=max(maxi,r-l+1);
                r++;
            }
            else{
                while(m[s[r]]>0){
                    m[s[l]]--;
                    l++;
                }
            }
        }

        return maxi;
    }
};