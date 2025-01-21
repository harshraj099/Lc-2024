class Solution {
public:
    bool isHappy(int n) {
        int t=20;
        while(t--){
            if(n==1)return true;
            int sum=0;
            while(n>0){
                int digit=n%10;
                sum+=(digit*digit);
                n=n/10;
            }
            n=sum;
        }
        return false;
    }
};