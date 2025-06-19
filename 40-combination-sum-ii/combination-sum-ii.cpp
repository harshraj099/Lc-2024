class Solution {
public:
    void f(int i,vector<int>& candidates, int target,int n, vector<int>&v,vector<vector<int>>&res){
        if(target==0){
             res.push_back(v);
            return;
        }
        
        for(int idx=i;idx<n;idx++){
            if(idx!=i && candidates[idx]==candidates[idx-1])continue;
            if(target-candidates[idx]>=0){
            v.push_back(candidates[idx]);
            f(idx+1,candidates,target-candidates[idx],n,v,res);
            v.pop_back();
            }
        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>v;
        f(0,candidates,target,n,v,res);
        return res;
    }
};