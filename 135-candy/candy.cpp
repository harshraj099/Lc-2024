class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     if(n==1)return 1;
    vector<int>candy(n,1);
    // left to right
        for(int i=1;i<n;i++){
          if(ratings[i]>ratings[i-1])candy[i]=candy[i-1]+1;
        }
        //right to left
        for(int i=n-2;i>=0;i--){
          if(ratings[i]>ratings[i+1])candy[i]=max(candy[i+1]+1,candy[i]);
        }
        int sum=0;
        for(auto it:candy)sum+=it;
        return sum;
    }
};