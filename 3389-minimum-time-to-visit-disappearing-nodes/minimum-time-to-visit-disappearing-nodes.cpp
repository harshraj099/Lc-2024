class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0}); //time,node
            vector<int>vis(n,0);
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int time=it[2];
            if(u==v)continue;
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<int>ans(n,1e9);
        ans[0]=0;
        while(!q.empty()){
            int ttm=q.top().first;
            int node=q.top().second;
            q.pop();
            if(vis[node])continue;
            vis[node]=1;
            // if(ttm<disappear[node]){
            //     ans[node]=ttm;
            // }
            // else ans[node]=-1;
            for(auto it:adj[node]){
                int neigh=it.first;
                int time=it.second;
                if(ttm+time<ans[neigh] && ttm+time<disappear[neigh]){
                    ans[neigh]=ttm+time;
                    q.push({ttm+time,neigh});
                }
            }
        }
        for(int i=0;i<ans.size();i++ )if(ans[i]==1e9)ans[i]=-1;
        return ans;
    }
};