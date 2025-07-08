class Solution {
public:
    int f(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
        vis[node]=1;
        int cnt=0;
        for(auto [nei,dir]:adj[node]){
            if(!vis[nei]){
                if(dir==0)cnt+=1+f(nei,adj,vis);
                else cnt+=f(nei,adj,vis);
            }
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // concept of forward and reverse direction
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        vector<int>vis(n,0);
        return f(0,adj,vis);
    }
};