class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;){
            int low=intervals[i][0],high=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=high){
                high=max(high,intervals[j][1]);
                j++;
            }
           ans.push_back({low,high});
           i=j;
        }

        return ans;
    }
};