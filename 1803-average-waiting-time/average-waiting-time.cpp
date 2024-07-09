class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double  ans=customers[0][1];
        double sum=customers[0][0]+customers[0][1];

        for(int i=1;i<customers.size();i++){
         if((sum-customers[i][0])>=0){ans+=customers[i][1]+(sum-customers[i][0]);
            sum+=customers[i][1];}
            else {
                ans+=customers[i][1];
               sum=customers[i][0]+customers[i][1]; 
            }
            // cout<<ans<<" ";  
        }

        return ans/customers.size();
    }
};