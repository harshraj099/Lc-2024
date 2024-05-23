class Solution {
public:
    void f(int idx,vector<int>& nums,vector<int>&v,vector<vector<int>>&vec){
        if(idx==nums.size()){
            vec.push_back(v);
            return;
        }

        // take
        v.push_back(nums[idx]);
        f(idx+1,nums,v,vec);
        v.pop_back();

        // leave
        f(idx+1,nums,v,vec);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>v;
        vector<vector<int>>vec;
        f(0,nums,v,vec);

    int cnt=0;
        for(auto it:vec){
            vector<int>temp=it;
            int fl=0;
            for(int i=0;i<temp.size();i++){
                for(int j=i+1;j<temp.size();j++){
                    if(abs(temp[i]-temp[j])==k){
                        fl=1;
                        break;
                    }
                }
                if(fl)break;
            }
            if(!fl)cnt++;
        }
        return cnt-1;
    }
};