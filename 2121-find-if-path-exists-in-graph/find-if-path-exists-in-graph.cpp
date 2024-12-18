class Solution {
public:
    bool isvisited(int i,vector<int>graph[],vector<int>&vis,int j){
        if(i==j)return true;

        for(auto neigh:graph[i]){
            if(!vis[neigh]){
                vis[neigh]=1;
           if(isvisited(neigh,graph,vis,j))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>graph[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>vis(n,0);
        vis[source]=1;

        return isvisited(source,graph,vis,destination);

    }
};