class Solution {
public:
    void merge(vector<int>& nums,int l,int r,int mid){    
        int left=l,right=mid+1;
          vector<int>temp;
        while(left<=mid && right<=r){
            if(nums[left]>nums[right]){
               temp.push_back(nums[right]);
                right++;
            }
          else {
            temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
                left++;
            }
              while(right<=r){
            temp.push_back(nums[right]);
                right++;
            }

            for(int i=l;i<=r;i++){
                nums[i]=temp[i-l];
            }
    }
    void mergesort(int l,int r,vector<int>&nums){
        if(l>=r)return;
        
        int mid=(l+r)/2;
        //left
        mergesort(l,mid,nums);
        //right
        mergesort(mid+1,r,nums);

        merge(nums,l,r,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        mergesort(0,nums.size()-1,nums);

        return nums;
    }
};