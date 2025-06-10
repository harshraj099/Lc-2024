class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
      k=k%n;
      vector<int>v=nums;
      for(int i=0;i<n;i++){
        nums[i]=v[(n-k+i)%n];
      }  

    }
};