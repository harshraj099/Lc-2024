class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // correct but tle

        //  int n=nums.size();
        // vector<int>prefix(n+1,0);
        // for(int i=0;i<n;i++){
        //     prefix[i+1]=prefix[i]+((nums[i]%2==1)?1:0);
        // }
        // int ct=0;
        // for(int i=0;i<n;i++){
        //     int l=0;
        //     while(l<=i){
        //         if(prefix[i+1]-prefix[l]==k){
        //             ct++;
        //         }
        //         l++;
        //     }
        // }
        // return ct;

        map<int,int>m;
        int odd=0;
        int res=0;
        m[0]=1; //ek to when odd==k wala case k liye
        for(auto it:nums){
             odd+=(it%2);
            res+=m[odd-k];
            m[odd]++;
        }

        return res;
    }
};