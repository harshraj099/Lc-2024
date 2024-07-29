class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int mid;
        int ans;
        // int missing;
        while(low<=high){
            mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
            if(missing <k)low=mid+1;
            else high=mid-1;
        }
        // arr[high]+more =arr[high]+(k-((arr[high])-(high+1))))
        return k+low;
    }
};