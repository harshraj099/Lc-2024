class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();

        int l=0,r=n-1;
        while(l<n-1 && arr[l]<=arr[l+1])l++;
        if(l==n-1)return 0;

        while(r>=1 && arr[r]>=arr[r-1])r--;

        int res=min(n-(l+1),r);

       int i=0;
        while(i<=l && r<n){
            if(arr[i]<=arr[r]){
                res=min(res,r-i-1);
                i++;
            }
            else r++;
        }

        return res;
    }
};