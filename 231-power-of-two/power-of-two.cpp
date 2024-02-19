class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(abs(n)<1)return false;
       if(n<0)return false;
       //double k=2;
       int x =log2(n);
       if((1<<x)==n)return true;
       return false;
    }
};