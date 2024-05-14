class Solution {
public:
    bool isPowerOfTwo(int n) {
    //    if(n<0)return false;
    //    //double k=2;
    //    int x =log2(n);
    //    if((1<<x)==n)return true;
    //    return false;
    if(n<=0)return false;
    long long ans=n&(n-1);
    cout<<ans;
    if(ans==0)return true;
    return false;
    }
};