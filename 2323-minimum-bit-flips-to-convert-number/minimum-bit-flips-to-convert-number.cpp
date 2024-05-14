class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct=0;
        while(start>0){
            if((start&1)!=(goal&1))ct++;
            start=start>>1;
            goal=goal>>1;
        }
        while(goal>0){
           if((goal&1)!=0)ct++; 
            goal=goal>>1;
        }

        return ct;
    }
};