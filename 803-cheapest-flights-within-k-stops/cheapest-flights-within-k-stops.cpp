class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        vector<pair<int,int>>adj[n];
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        queue<pair<int,pair<int,int>>>q;

        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        dist[src]=0;
        q.push({0,{src,k}});
        int mini=1e9;
        while(!q.empty()){
            int wt=q.front().first;
            int node=q.front().second.first;
            int ct=q.front().second.second;
            q.pop();
            if(node==dst){
                // return wt;
                mini=min(mini,wt);
            }
            if(ct>=0){
              for(auto it:adj[node]){
                if(wt+it.second<dist[it.first]){
                    dist[it.first]=wt+it.second;
                    q.push({wt+it.second,{it.first,ct-1}});
                }
            }
            }
            
        }

        if(mini!=1e9)return mini;
        return -1;
    }
};