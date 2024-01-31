class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size()-1;
        int mid;
        int n=citations.size();
        if(!n)return 0;
        int ans;
        while(low<=high){
            mid=(low+high)/2;
            if(citations[mid]>=n-mid ){ans=n-mid;
                high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};