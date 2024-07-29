class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());
         int high=maxi;
        int mid;
        int ans;
        while(low<=high){
            mid=(low+high)/2;
            int sum=0;
            int cnt=0;
            for(int i=0;i<weights.size();i++){
                sum+=weights[i];
                if(sum<=mid)continue;
                // if((sum+weights[i])<=mid)sum+=weights[i];
                else{
                    // cout<<sum<<" ";
                    cnt++;
                    sum=weights[i];
                }
            }
            cnt++;
            // cout<<cnt<<" "<<mid<<endl;
            if(cnt<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};