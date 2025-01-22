class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)return {};
        vector<string> ans;
        int ini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                continue;
            }
            else{
     if(ini!=nums[i-1])ans.push_back(to_string(ini)+"->"+to_string(nums[i-1]));
   else     ans.push_back(to_string(ini));
             ini=nums[i];
            }
        }
   if(ini!=nums[nums.size()-1])ans.push_back(to_string(ini)+"->"+to_string(nums[nums.size()-1]));
   else     ans.push_back(to_string(ini));


    return ans;
    }
};