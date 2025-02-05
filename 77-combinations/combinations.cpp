class Solution {
public:
    void f(int idx,int n,int k, vector<vector<int>>&ans,vector<int>&v){
        if(idx>n){
            if(k==0){
                ans.push_back(v);
            return; 
            }
            return;
        }
        if(k==0){
            ans.push_back(v);
            return;
        }
        // take
        v.push_back(idx);
        f(idx+1,n,k-1,ans,v);
        v.pop_back();

        // not take
        f(idx+1,n,k,ans,v);


    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> ans;
        vector<int>v;
       f(1,n,k,ans,v); 
       return ans;
    }
};