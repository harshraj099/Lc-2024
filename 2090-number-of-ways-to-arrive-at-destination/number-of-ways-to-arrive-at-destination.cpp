class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(int i=0;i<roads.size();i++){
            long long from=roads[i][0];
            long long to=roads[i][1];
            long long time=roads[i][2];
            adj[from].push_back({to,time});
              adj[to].push_back({from,time});
        }
        vector<long long>dist(n,1e15);
        vector<long long>ways(n,0);
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});  // dist,node
        dist[0]=0;
        ways[0]=1;
        int m=(int)(1e9+7);
           while(!q.empty()){
           long long dis=q.top().first;
            long long node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                if(it.second+dis<dist[it.first]){
                    dist[it.first]=it.second+dis;
                    ways[it.first]=ways[node];
                    q.push({dist[it.first],it.first});
                }
                else if (it.second+dis==dist[it.first]){
                    ways[it.first]=(ways[node]+ways[it.first])%m;
                }
                }
            }

        return ways[n-1];
    }
};