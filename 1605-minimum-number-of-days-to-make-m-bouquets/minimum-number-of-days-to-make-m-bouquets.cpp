class Solution {
public:
    int f(int day,vector<int>& bloomDay,int k){
        int sum=0;
        int ct=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                sum++;
            }
            else{
                ct+=(sum/k);
                sum=0;
            }
        }
         ct+=(sum/k);
         return ct;
    }
        int minDays(vector<int>& bloomDay, int m, int k) {
        int l=0;
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int r=maxi;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            int num=f(mid,bloomDay,k);
            if(num<m){
                l=mid+1;
            }
            else {
             r=mid-1;
            }
        }
        if(l>maxi)return -1;
        return l;
    }
};