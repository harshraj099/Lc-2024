class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     int maxi=-1e9,sumup=0,mini=1e9,sumdown=0,sum=0;
     int n=nums.size();

     for(auto it:nums){
        sumup=max(it,sumup+it);
        maxi=max(maxi,sumup);
        sumdown=min(it,sumdown+it);
        mini=min(mini,sumdown);

        sum+=it;
     }

     return maxi>0?max(maxi,sum-mini):maxi;
    }
};