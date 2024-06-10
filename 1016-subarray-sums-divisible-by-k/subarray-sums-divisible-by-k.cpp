class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        map<int,int>m;
        m[0]=1;  // base case;
        for(auto it:nums){
            sum+=(it);
            int rem=sum%k;
            if(rem<0)rem+=k;
            if(m.find(rem)!=m.end()){
                cnt+=m[rem];
                m[rem]+=1;
            }
            else m[rem]=1;
        }
        return cnt;
    }
};