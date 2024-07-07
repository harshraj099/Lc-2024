class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int divident=numBottles/numExchange;
        int rem=numBottles%numExchange;
        int ans=numBottles+divident;
        int remaining=divident+rem;
        while(true){
           if(remaining/numExchange)ans+=remaining/numExchange;
           else break;
            rem=remaining%numExchange;
            remaining=remaining/numExchange+rem;
        }

        return ans;
    }
};