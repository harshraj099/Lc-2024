class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos,neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0)pos.push_back(nums[i]);
            if(nums[i]<0)neg.push_back(nums[i]);
        }
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(i%2==0)v[i]=(pos[i/2]);
             if(i%2!=0)v[i]=(neg[(i-1)/2]);
        }
        return v;
    }
};