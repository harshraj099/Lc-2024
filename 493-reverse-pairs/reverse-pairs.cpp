class Solution {
public:
    int merge(int i,int mid,int j,vector<int>& nums){
        int l=i,r=mid+1;

        int cnt=0;
        while(l<=mid && r<=j){
            if(nums[l]>2LL*nums[r]){
                cnt+=(mid-l+1);
                r++;
            }
            else l++;
        }
        l=i,r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=j){
            if(nums[l]>nums[r]){
                temp.push_back(nums[r]);
                r++;
            }
            else {
                temp.push_back(nums[l]);
                l++;
            }
        }

        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }

        while(r<=j){
        temp.push_back(nums[r]);
        r++;
        }

        for(int k=0;k<temp.size();k++){
            nums[k+i]=temp[k];
        }

        return cnt;
    }
    int f(int i,int j,vector<int>& nums){
        if(i>=j)return 0;
        int mid=(i+j)/2;
        int left=f(i,mid,nums);
        int right=f(mid+1,j,nums);

       int ans=merge(i,mid,j,nums);

        return ans+left+right; 
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
       return f(0,n-1,nums);
    }
};