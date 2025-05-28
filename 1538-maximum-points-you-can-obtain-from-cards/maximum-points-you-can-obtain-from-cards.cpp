class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+cardPoints[i];
        }
        int maxi=0;
        int len=n-k;
        if(len==0)return prefix[n];
        for(int i=1;i<=n;i++){
          if(i-len>=0)maxi=max(maxi,prefix[n]-(prefix[i]-prefix[i-len]));
        }

        return maxi;
    }
};