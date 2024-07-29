class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())return -1;
        int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
        int mini=1e8;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]<=mid)sum+=nums[i];
                else{
                    cnt+=1;
                    sum=nums[i];
                //    if(mid>=nums[i])sum=nums[i];
                //    else sum=0;
                }
            }
        //   if(sum>0) cnt+=1;
           cnt+=1;

            if(cnt==k){
                mini=min(mini,mid);
                high=mid-1;
            }
          else if(cnt<k){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};