class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if((jug1Capacity+jug2Capacity)<targetCapacity)return false;
        int div=__gcd(jug1Capacity,jug2Capacity);
        if(targetCapacity%div==0)return true;
        return false;
    }
};