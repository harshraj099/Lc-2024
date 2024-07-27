class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp=nums;
        for(int i=k;i<n;i++){
            temp[i]=nums[i-k];
        }
        for(int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
        }
        nums=temp;
    }
};