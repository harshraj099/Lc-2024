class Solution {
public:

   void getsub(int idx,vector<vector<int>>&v,vector<int>&nums,int n,vector<int>&vec){
        // vector<int>vec;
        if(idx==n){
                v.push_back(vec);
            return ;
        }
        //not take
        getsub(idx+1,v,nums,n,vec);

        //take
        vec.push_back(nums[idx]);
         getsub(idx+1,v,nums,n,vec);
         vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>>v;
    //     vector<int>vec;
    //     getsub(0,v,nums,nums.size(),vec);
    //   return v;


        // or
    int n=nums.size();
      int subsets=1<<n;

    vector<vector<int>>v;
        for(int i=0;i<subsets;i++){
            vector<int>vec;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0)vec.push_back(nums[j]);
            }
            v.push_back(vec);
        }

        return v;
    }
};