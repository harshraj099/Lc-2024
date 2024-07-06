class Solution {
public:
    int passThePillow(int n, int time) {
        int q=time/(n-1);
        int r=time%(n-1);

        if(q%2==1){
           return n-r; 
        }
        else  return r+1; 
    }
};