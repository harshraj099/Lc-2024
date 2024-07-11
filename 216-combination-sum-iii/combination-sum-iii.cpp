class Solution {
public:
    void f(int idx,vector<int>&temp,vector<int>&v,vector<vector<int>>&ans,int target,int n){
       if(target==0 && n>0) return;
        if(idx<0 && target>0)return;
        if(n==0 ){
         if(target==0)ans.push_back(v);
            return ;
        }
        
        // take 
        if(target>=temp[idx]){
        v.push_back(temp[idx]);
        f(idx-1,temp,v,ans,target-temp[idx],n-1);
        v.pop_back();
}
        // not take
        f(idx-1,temp,v,ans,target,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<=k || n>45 || n>=k*9)return {};
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>temp={1,2,3,4,5,6,7,8,9};
        f(8,temp,v,ans,n,k);

        return ans;
    }
};