class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]!=1){
            sum+=customers[i];
            customers[i]=0;
            }
        }
        int maxi=0;
        int ct=0;
         for(int i=0;i<minutes;i++){
          ct+=customers[i];
        }
        maxi=max(maxi,ct);
          for(int i=minutes;i<n;i++){
          ct+=customers[i];
          ct-=customers[i-minutes];
           maxi=max(maxi,ct);
        }
        return sum+maxi;
    }
};