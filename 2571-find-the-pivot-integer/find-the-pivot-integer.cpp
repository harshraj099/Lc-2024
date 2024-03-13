class Solution {
public:
    int pivotInteger(int n) {
        int i=1;
        while(i<=n){
            int l=(i*(i+1))/2;
            int r=((n-i+1)*(i+n))/2;
            if(l==r)return i;
            i++;
        }
        return -1;
    }
};