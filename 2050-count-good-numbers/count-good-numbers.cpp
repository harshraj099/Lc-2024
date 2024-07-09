class Solution {
public:
    const int mod=1e9+7;

    long long f(long long x,long long y){
        if(y==0)return 1;
        long long ans=f(x,y/2);
        ans*=ans;
        ans%=mod;
        if(y%2)ans*=x;
        ans%=mod;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2, odd = n/2;

        return (f(5,even)*f(4,odd))%mod;
    }
};
