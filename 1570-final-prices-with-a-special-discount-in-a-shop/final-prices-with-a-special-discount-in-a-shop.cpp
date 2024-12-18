class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
      vector<int>ans;

      for(int i=0;i<n;i++){
        int mini=prices[i]+1;
        for (int j=i+1;j<n;j++){
            if(prices[j]<=prices[i]){
                mini=prices[j];
                break;
            }
        }
        if(mini<=prices[i]){
            ans.push_back(prices[i]-mini);
        }
        else   ans.push_back(prices[i]);
      }  

      return ans;
    }
};