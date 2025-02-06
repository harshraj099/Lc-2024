class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int mul=nums[i]*nums[j];
                m[mul]++;
            }
        }

        for(auto it:m){
            // cout<<it.first<<endl;
            int val=it.second;
        if(val>=2){
            int ct=val*(val-1);
            ct=ct/2;
            res+=ct*8;
        }
        }

        return res;
    }
};