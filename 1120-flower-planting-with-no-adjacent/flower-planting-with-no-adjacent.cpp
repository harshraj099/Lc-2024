class Solution {
public:
      bool safe(int node, vector<int> adj[], vector<int>& color, int rang) {
        for (auto it : adj[node]) {
            if (color[it] == rang) return false;
        }
        return true;
    }

    void f(int node, vector<int> adj[], int m, vector<int>& color, vector<int>& vis) {
        for (int i = 1; i <= m; i++) {
            if (safe(node, adj, color, i)) {
                color[node] = i;
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        f(it, adj, m, color, vis);
                    }
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n+1];
        for(auto it:paths){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n+1,0);
         vector<int> color(n+1, -1);
        // vector<int>color(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                 color[i]=0;
        f(i, adj, 4, color, vis);
            }
        }
        color.erase(color.begin(),color.begin()+1);
        return color;
    }
};