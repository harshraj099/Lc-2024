class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
           if(intervals.size()==0)return {newInterval};

            vector<vector<int>>res;
            vector<int>idx={0,0};
            for(auto it:intervals){
                if(it[1]<newInterval[0]){
                    res.push_back({it[0],it[1]});
                }
                else if(it[1]>=newInterval[0]){

                    if(idx[0]==0 && idx[1]==0){
                    if(it[0]<=newInterval[0]){
                        idx={it[0],max(it[1],newInterval[1])};
                    }
                    else {
                    if(it[0]<=newInterval[1]) idx={newInterval[0],max(it[1],newInterval[1])};
                    else {
                         res.push_back({newInterval[0],newInterval[1]});
                          idx={it[0],it[1]};
                          }
                    }
                    }

                    else{
                      if(it[0]<=idx[1]){
                        idx={idx[0],max(it[1],idx[1])};
                    }
                  else {
                    res.push_back({idx[0],idx[1]});
                    idx={it[0],it[1]};
                  }
                    }
                }
            }
            if(idx[0]==0 && idx[1]==0)  res.push_back({newInterval[0],newInterval[1]});
         else res.push_back({idx[0],idx[1]});
            return res;
    }
};