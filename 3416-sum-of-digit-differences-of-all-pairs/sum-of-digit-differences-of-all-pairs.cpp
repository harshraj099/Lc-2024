class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
       long long sum=0;
       map<long long,vector<char>>m;
        for(int i=0;i<nums.size();i++){
                string a=to_string(nums[i]);
                for(int k=0;k<a.size();k++){
                   m[k].push_back(a[k]);
                }
        }
       for(auto it:m){
        vector<char>temp=it.second;
        sort(temp.begin(),temp.end());
        long long count=0;
        for(int i=1;i<temp.size();i++){
            if(temp[i]==temp[i-1]){
                count++;
                sum+=i;
                sum-=count;
            }
            else {
                sum+=i;
                count=0;
            }
        }
       }

       return sum;
    }
};