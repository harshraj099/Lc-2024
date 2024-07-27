class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        long long n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n-2;j++){
            if(j!=i+1 && nums[j]==nums[j-1])continue;

            long long p=j+1,q=n-1;
            while(p<q){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[p];
                sum+=nums[q];
                if(sum==target){
                    vector<int>v={nums[i],nums[j],nums[p],nums[q]};
                    ans.push_back(v);
                    p++;
                    q--;
                       // remove duplicate
            while(p<q && nums[p]==nums[p-1])p++;
            while(p<q && nums[q]==nums[q+1])q--;
                }
                else if(sum<target){
                    p++;
                }
                else q--;
            }
        }
        }
        return ans;
    }
};