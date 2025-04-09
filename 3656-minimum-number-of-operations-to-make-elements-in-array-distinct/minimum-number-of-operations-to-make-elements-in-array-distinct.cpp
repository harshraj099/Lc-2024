class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();

            int ct=1;
            map<int,int>m;
            m[nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            if(m.find(nums[i])==m.end()){
                ct+=1;
                m[nums[i]]=1;
            }
            else break;
        }
        int q=(n-ct)/3;
        int rem=(n-ct)%3;
        int ans=0;
        if(rem>0){
            q+=1;
            return q;
        }
       else return q;
    }
};