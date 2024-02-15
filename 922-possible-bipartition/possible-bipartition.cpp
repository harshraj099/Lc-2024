class Solution {
public:
int idx=0;
    bool iscyclic(int node,vector<int>adj[],vector<int>&vis,vector<int>&color){
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    color[it]=!color[node];
                   if(!iscyclic(it,adj,vis,color))return false;
                }
                if(vis[it] && color[it]==color[node])return false;
    }
    return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        int m=dislikes.size();
        for(int i=0;i<m;i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n+1,0);
         vector<int>color(n+1,0);
        int idx=0;
        for(int i=1;i<=n;i++)
      { 
           if(!vis[i]){
               vis[i]=1;
               if(!iscyclic(i,adj,vis,color))return false;
        }
        }
      return true;
    }
};