class Solution {
public:

    // bool check(int bal,int i,vector<int>& gas, vector<int>& cost,int n,int ct){
    //     if(ct==n)return true;
    //     // cout<<bal;
    //     if(bal>=cost[i] && check(bal-cost[i]+gas[(i+1)%n],(i+1)%n,gas,cost,n,ct+1)) return true;

    //     return false;
    // }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
           if (totalGas < totalCost) {
            return -1;
        }
        
        int currentGas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];
            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;        
    }
};