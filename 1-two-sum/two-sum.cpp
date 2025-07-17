class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>>pr;
        for(int i=0;i<nums.size();i++){
            pr.push_back(make_pair(nums[i],i));
        }
         sort(pr.begin(),pr.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if((pr[l].first+pr[r].first)==target)return {pr[l].second,pr[r].second};
            else if((pr[l].first+pr[r].first)<target){
                l++;
            }
            else r--;
        }
        return {};
    }
};