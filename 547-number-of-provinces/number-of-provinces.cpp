class Solution {
public:
    void dfs(int node,  vector<vector<int>>&adj, vector<int>&vis){
        for(auto ng:adj[node]){
            if(!vis[ng]){
                vis[ng]=1;
                dfs(ng,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<int>vis(n+1,0);
        //  vector<int>adj[n+1];
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
      int ct=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ct+=1;
                dfs(i,adj,vis);
            }
        }

        return ct;
    }
};