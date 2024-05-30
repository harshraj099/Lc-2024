class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a=0,b=0;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            a=arr[i];
            for(int j=i+1;j<n;j++){
                a^=arr[j];
                b=arr[j];
                for(int k=j;k<n;k++){
                    b^=arr[k];
                    if(a==b)cnt++;
                }
            }
        }

        return cnt;
    }
};