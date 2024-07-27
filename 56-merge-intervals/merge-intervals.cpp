class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int left,right;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==1)return intervals;
        else
{        left=intervals[0][0];
        right=intervals[0][1];
        vector<vector<int>>v;
        for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=right && intervals[i][1]>=right)right=intervals[i][1];
 else if(intervals[i][0]<=right && intervals[i][1]<right)goto jump;
        else{
            vector<int>vec;
            vec.push_back(left);
            vec.push_back(right);
            v.push_back(vec);
            left=intervals[i][0];
            right=intervals[i][1];
        }
        jump:
        if(i==intervals.size()-1){
            vector<int>vec;
             vec.push_back(left);
            vec.push_back(right);
            v.push_back(vec);
        }
        }
        return v;}
    }
};