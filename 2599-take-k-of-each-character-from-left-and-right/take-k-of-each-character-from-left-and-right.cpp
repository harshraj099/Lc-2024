class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0)return 0;
        vector<int>v(3,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        if(v[0]<k || v[1]<k || v[2]<k)return -1;

        int l=0,r=0;
        int res=n;
        while(r<n){
            if((v[s[r]-'a']-1)>=k){
                v[s[r]-'a']--;
                r++;
                 res=min(res,n-(r-l));
            }
            else {
            //    while(l<r){
            //     v[s[l]-'a']++;
            //     l++;
            //     }
             v[s[l]-'a']++;
                l++;
            }
        }
        // cout<<"hi";
        return res;
    }
};