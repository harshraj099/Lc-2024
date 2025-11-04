class Solution {
public:
    void f(int idx,int n,vector<int>& v,vector<vector<int>>&ans,vector<int>& candidates, int target){
        if(target==0){ans.push_back(v);
        return;}

        if(idx==n){
          if(target==0)ans.push_back(v);
            return ;
        }

        for(int i=idx;i<n;i++){
            if( i-1>=idx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]<=target){
                v.push_back(candidates[i]);
                f(i+1,n,v,ans,candidates,target-candidates[i]);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        f(0,n,v,ans,candidates,target);
        return ans;
    }
};