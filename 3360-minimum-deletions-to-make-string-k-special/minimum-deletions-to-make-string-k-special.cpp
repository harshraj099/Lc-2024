class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>v;
        map<char,int>m;
        for(int i=0;i<word.size();i++){
            m[word[i]]++;
        }
        for(auto it:m)v.push_back(it.second);
        sort(v.begin(),v.end());
    int ans=0,check=word.size();
        for(int i=0;i<v.size();i++){
            int ref_cnt=v[i];
            int temp=ans;
            for(int j=v.size()-1;j>i;j--){
                if(v[j]-v[i]<=k)break;
                temp+=v[j]-v[i]-k;
            }
            check=min(check,temp);
            ans+=v[i];
        }

        return check;
    }
};