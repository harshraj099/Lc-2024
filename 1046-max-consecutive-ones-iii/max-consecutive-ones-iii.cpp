class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxi=0;
        while(l<=r && r<nums.size()){
            if(nums[r]==1){
                maxi=max(maxi,r-l+1);
                r++;
            }
            else if(nums[r]==0 && k>0){
                maxi=max(maxi,r-l+1);
                r++;
                k--;
            }
            else{
                if(nums[l]==0){
                    if(k==0){
                        l++;
                        r++;
                    }
                    else{
                    k++;
                    l++;
                    }
                   
                }
                else {
                    l++;
                }
            }
            // cout<<maxi<<" ";
        }
        return maxi;
    }
};