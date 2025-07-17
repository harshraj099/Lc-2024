class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        int prefix=1,suffix=1,zeros=0,ind;
        for(int i=0;i<n;i++){
            if(nums[i]==0){  
            ind=i;
            zeros++;
        }
        prefix*=nums[i];
        }
        if(zeros>1)return res;
        if(zeros==1){
            int mul=1;
            for(auto it:nums)if(it!=0)mul*=it;
            res[ind]=mul;
            return res;
        }
        for(int i=n-1;i>=0;i--){
            prefix=prefix/nums[i];
            if(i+1<n)suffix*=nums[i+1];
            res[i]=prefix*suffix;
        }

        return res;
    }
};