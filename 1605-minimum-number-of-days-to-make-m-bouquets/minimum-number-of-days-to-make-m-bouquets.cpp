class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
       int high=*max_element(bloomDay.begin(),bloomDay.end());
       int mid;
       int days=-1;
       while(low<=high){
           mid=(low+high)/2;
           int cnt=0;
                 int bokey=0;
           for(int i=0;i<bloomDay.size();i++){
               if(bloomDay[i]<=mid)cnt++;
               else{
                   bokey+=cnt/k;
                    cnt=0;
               }
               }
                bokey+=cnt/k;
           if(bokey>=m){
              days=mid;
              high=mid-1; 
           }
           else low= mid+1;
       }
        return days;
    }
};