class Solution {
public: 
    void f(int i,vector<int>& digits, int target,int n, vector<int>&v,vector<vector<int>>&res,int k){
        if(target==0 && k==0){
             res.push_back(v);
            return;
        }
        
        for(int idx=i;idx<n;idx++){
            if(idx!=i && digits[idx]==digits[idx-1])continue;
            if(target-digits[idx]>=0){
            v.push_back(digits[idx]);
            f(idx+1,digits,target-digits[idx],n,v,res,k-1);
            v.pop_back();
            }
        } 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>digits={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>res;
        vector<int>v;
        f(0,digits,n,9,v,res,k);
        return res;
    }
};