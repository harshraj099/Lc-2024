class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=1;i<n;i++){
            map<char,int>m;
            for(int j=i;j>=0;j--){
                m[s[j]]++;
             int maxi=0,mini=1e9;
                if(m.size()>1){
                    for(auto it:m){
                         maxi=max(maxi,it.second);
                         mini=min(mini,it.second);
                    }
                ans+=(maxi-mini);
                }    
            }
        }

        return ans;
    }
};