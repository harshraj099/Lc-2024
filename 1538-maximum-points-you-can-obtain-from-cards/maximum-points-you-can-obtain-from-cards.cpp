class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int w=n-k;
        int s=0;
        for(int i=0;i<w;i++){
            s+=cardPoints[i];
        }
        int mini=s;
        for(int i=w;i<n;i++){
            s-=cardPoints[i-w];
            s+=cardPoints[i];
            mini=min(mini,s);
        }
        return sum-mini;
    }
};