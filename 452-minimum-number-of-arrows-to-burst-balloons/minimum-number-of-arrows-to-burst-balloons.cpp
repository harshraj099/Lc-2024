class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
         int cnt=0;
        int ptr=points[0][1];
         for(int i=1;i<points.size();i++){
            if(points[i][0]<=ptr && points[i][1]>=ptr)continue;
           else if(points[i][0]<=ptr && points[i][1]<ptr){
            ptr=points[i][1];
           }
            else{
                cnt++;
                ptr=points[i][1];
            }
         }

         return cnt+1;

    }
};