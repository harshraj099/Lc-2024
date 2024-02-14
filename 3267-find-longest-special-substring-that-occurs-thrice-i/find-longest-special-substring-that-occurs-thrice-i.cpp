class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int>m;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            m[{s[i],1}]++;
          cnt=1;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]==s[j+1]){
                    cnt++;
                     m[{s[i],cnt}]++;
                }
                else break;
            }
        }
        int ans=0;
        for(auto it:m){
            if(it.second>=3)ans=max(ans,it.first.second);
        }
        return (ans==0)?-1:ans;
    }
};