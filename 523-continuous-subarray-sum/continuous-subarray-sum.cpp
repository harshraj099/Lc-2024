class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size();
        map<int,int>m;
        m[0]=-1;     
        // O(n) complexity
        int sum=0;
        for(int i=0;i<n;i++){
      sum+=nums[i];
      int rem=sum%k;
      cout<<rem<< " ";
      if(m.find(rem)!=m.end()){
         if((i-m[rem])>1) return true;
      }
      else {
        m[rem]=i;
      }
        }
    //    if(m.find(sum%k)!=m.end()){
    //     return (n-m[sum%k])>1;
    //   }
            return false;
    }
};