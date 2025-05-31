class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=0;i<n;i++){
           if(i+1<n && intervals[i+1][0]<=e){
            e=max(e,intervals[i+1][1]);
           }
           else {
            ans.push_back({s,e});
           if(i+1<n) s=intervals[i+1][0];
           if(i+1<n) e=intervals[i+1][1];
           }
        }

        return ans;
    }
};