class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
         queue<pair<int,pair<int,int>>>q;
         q.push({0,{src,0}}); // dist,node
        dist[src]=0;
        int mini=1e9;
        while(!q.empty()){
            int len=q.front().first;
            int from=q.front().second.first;
            int ct=q.front().second.second;
                q.pop();
                if(from==dst){
                    mini=min(mini,len);
                }
            for(auto it:adj[from]){
                int to=it.first;
                int new_len=len+it.second;
                if(new_len<dist[to] && ct<=k){
                    q.push({new_len,{to,ct+1}});
                    dist[to]=new_len;
                }
            }
        }
        if(mini!=1e9)return mini;
        return -1;
    }
};