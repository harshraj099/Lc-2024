class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,int target){
        if(node==target)return true;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                if(dfs(it,adj,vis,target))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vis[source]=1;
       return dfs(source,adj,vis,destination);
    }
};