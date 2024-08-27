class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        vector<double>dist(n,0);
        queue<pair<double,double>>q;
        q.push({start_node,1});
        dist[start_node]=1;
        while(!q.empty()){
            int node=q.front().first;
            double len=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                //   cout<<it.first<<" "<<double(it.second*len)<<endl;
                    if(it.second*len>dist[it.first]){
                        dist[it.first]=it.second*len;
                        q.push({it.first,it.second*len});
                        // cout<<it.first<<" "<<dist[it.first]<<endl;
                    }
                }
        }
        return dist[end_node];
    }
};