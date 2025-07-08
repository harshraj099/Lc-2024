class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // min dist type q
        int n=patience.size();
        queue<pair<int,int>>q;
        q.push({0,0});  // dist, node
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(n,1e9);
        dist[0]=0;
        int burntime=0;
        while(!q.empty()){
            int distance=q.front().first;
            int node=q.front().second;
            q.pop();
           if(node!=0) burntime=max(burntime,distance+((distance-1)/patience[node])*patience[node]);
            for(auto it:adj[node]){
                if(distance+2<dist[it]){
                    dist[it]=distance+2;
                    q.push({dist[it],it});
                }
            }
        }

        return burntime+1;
    }
};