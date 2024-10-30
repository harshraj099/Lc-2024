class Solution {
public:

    // int lisf(int i,vector<int>& nums,int n,int &prev){
    //     if(i==n)return 0;

    //     int take=0;
    //     if(nums[i]>prev)take=1+lisf(i+1,nums,n,nums[i]);

    //     int nt=lisf(i+1,nums,n,prev);

    //     return max(take,nt);
    // }

    // int ldsf(int i,vector<int>& nums,int n,int prev){
    //     if(i==n)return 0;

    //     int take=0;
    //     if(nums[i]<prev)take=1+ldsf(i+1,nums,n,nums[i]);

    //     int nt=ldsf(i+1,nums,n,prev);

    //     return max(take,nt);
    // }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
       
       vector<int>lis(n,1);
       vector<int>lds(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
            if(nums[j]<nums[i])lis[i]=max(lis[i],1+lis[j]);
            }
        }
       for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
            if(nums[j]<nums[i])lds[i]=max(lds[i],1+lds[j]);
            }
        }

        for(int i=0;i<n;i++){
           if(lis[i]>1 && lds[i]>1) ans=max(ans,lis[i]+lds[i]-1);
        }

        // cout<<ans;
        return n-ans;
       
    }
};