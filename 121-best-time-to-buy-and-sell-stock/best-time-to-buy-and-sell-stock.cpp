class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=1e9;
        int profit=0;
        for(auto it:prices){
            mini=min(mini,it);
            profit=max(profit,it-mini);
        }

        return profit;
    }
};