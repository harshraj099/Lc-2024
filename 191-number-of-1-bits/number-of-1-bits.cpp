class Solution {
public:
    int hammingWeight(int n) {
        int ct=0;
        while(n>0){
            ct+=(n&1);
            n=n>>1;
        }
        return ct;
    }
};