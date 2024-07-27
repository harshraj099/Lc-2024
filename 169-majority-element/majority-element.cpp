class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // map<int,int>m;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        // }
        // int ans;
        // for(auto x:m){
        //     if(x.second>n/2)ans=x.first;
        // }
        // return ans;

        // moore voting algorithm

        int cnt=0;
        int ele;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i])cnt++;
            else cnt--;
        }

        // check if more than n/2
        int ct=0;
        for(auto it:nums){
            if(it==ele)ct++;
        }
        if(ct>=n/2)return ele;
        else return -1;
    }
};