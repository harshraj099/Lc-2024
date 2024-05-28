class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0;
        int n=s.size();
        int maxi=0;
        int cost=0;
        int l=0;
        for(int r=0;r<n;r++){
            cost+=abs(s[r]-t[r]);
               while(cost>maxCost){
                  cost-=abs(s[l]-t[l]);
                  l++;
               }
            maxi=max(maxi,r-l+1);
            }
        return maxi;
    }
};