class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int,string>m;
        int n=names.size();
        for(int i=0;i<n;i++){
            m[heights[i]]=names[i];
        }

        for(auto it:m){
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};