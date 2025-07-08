class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>vis(n,0);
    priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
// priority_queue<
//     Type,
//     Container (usually vector<Type>),
//     Comparator
// > name;
    pq.push({0,0});  //wt, index
        int sum=0;
        while(!pq.empty()){
            int index=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[index])continue;
            vis[index]=1;
            sum+=wt;
            for(int i=0;i<n;i++){
                int wt=abs(points[index][1]-points[i][1])+
                abs(points[index][0]-points[i][0]);
                if(!vis[i])pq.push({wt,i});
            }
        }
        return sum;
    }
};