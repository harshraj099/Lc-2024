class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prev=0;
        // if(k==0)return 0;
        map<int,int>m;
        m[0]=1;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            prev+=nums[i];
            if(m.find(prev-k)!=m.end()){
                ans+=m[prev-k];
            }
            m[prev]++;
        }
            return ans;
    }
};