class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int ct1=0,ct2=0;
        
        for(int i=0;i<n;i++){
            if(ct1==0 && nums[i]!=ele2){
                ct1=1;
                ele1=nums[i];
            }
            else if(ct2==0 && nums[i]!=ele1){
                ele2=nums[i];
                ct2=1;
                }
                else if(nums[i]==ele1)ct1++;
                else if(nums[i]==ele2)ct2++;
            else {
                ct1--;
                ct2--;
            }
        }
    // cout<<ele1<<" "<<ele2;
      ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ele1) ct1++;
        if (nums[i] == ele2) ct2++;
    }
    // cout<<ct1<<" "<<ct2;
    int mini = (n / 3) + 1;
    // cout<<mini;
    vector<int>res;
    if(ct1>=mini)res.push_back(ele1);
    if(ct2>=mini)res.push_back(ele2);
        return res;
            }
};