class Solution {
public:
    
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&quiet,int &mini,int &idx){
        if(quiet[node]<=mini){
            mini=quiet[node];
            idx=node;
        }
        vis[node]=1;
        for(auto it:adj[node]){
           if(!vis[it])dfs(it,vis,adj,quiet,mini,idx);
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int>adj[quiet.size()];
        for(int i=0;i<richer.size();i++){
            int u=richer[i][1];
            int v=richer[i][0];
            adj[u].push_back(v);
        }
        vector<int>ans;
        for(int i=0;i<quiet.size();i++){
            vector<int>vis(quiet.size(),0);
            int mini=INT_MAX,idx;
            dfs(i,vis,adj,quiet,mini,idx);
            ans.push_back(idx);
        }
        return ans;
    }
};