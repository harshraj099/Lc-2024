class Solution {
public:
    int smallestNumber(int n) {
        int len=0;
        while(n>0){
            len++;
            n=n>>1;
        }
        return pow(2,len)-1;
    }
};