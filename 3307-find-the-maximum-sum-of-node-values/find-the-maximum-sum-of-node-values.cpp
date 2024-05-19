class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
    long long sacrifice=1e10;
    long long ct=0;
      for(int i=0;i<nums.size();i++){
        long long original=nums[i];
        long long transformed=(nums[i]^k);

            if(transformed>original){
                sum+=transformed;
                sacrifice=min(sacrifice,transformed-original);
                ct++;
            }
            else {
                sum+=original;
                sacrifice=min(sacrifice,original-transformed);
            }
      }
        if(ct%2==0)return sum;
        else return sum-sacrifice;
    }
};