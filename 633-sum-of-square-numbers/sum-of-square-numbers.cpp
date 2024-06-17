class Solution {
public:
    bool judgeSquareSum(int c) {
        long long r=sqrt(c);
        long long l=0;
        while(l<=r){
            long long sum=l*l+r*r;
            if(sum==c)return true;
            if(sum<c)l=l+1;
            else r=r-1;
        }
        return false;
    }
};