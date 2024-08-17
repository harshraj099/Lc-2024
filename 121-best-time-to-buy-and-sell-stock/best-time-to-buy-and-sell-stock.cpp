class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int track=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>track){
                maxi=max(maxi,prices[i]-track);
            }
            track=min(prices[i],track);
        }
        return maxi;
    }
};