class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        int left=0,right=0;
        int least=500;
        for(int i=0;i<strs.size();i++){
               string k=strs[i];
               if(k.size()<least)least=k.size();
            }
        int len=-1;
        while(left<least && right<least){
            int fl=0;
            for(int i=0;i<strs.size()-1;i++){
                string s=strs[i],st=strs[i+1];
                if(s[right]!=st[right]){
                    fl=1;
                    break;
                }
            }
            if(fl){
                len=max(len,right-left);
                break;
           }
             right++;
        }
        len=max(len,right-left);
        string ans="";
        string p=strs[0];
        for(int i=0;i<len;i++){
            ans+=p[i];
        }
        return ans;
    }
};