class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q; //stop,node,price;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
                int from=flights[i][0];
                int to=flights[i][1];
                int cost=flights[i][2];
                adj[from].push_back({to,cost});
        }
             while(!q.empty()){
                 int stop=q.front().first;
                 int node=q.front().second.first;
                 int cost=q.front().second.second;
                 q.pop();
                 for(auto it:adj[node]){
                     int nxt=it.first;
                     int money=it.second;
                    if(cost+money<dist[nxt] && stop<=k){
                        dist[nxt]=cost+money;
                     q.push({stop+1,{nxt,dist[nxt]}});
                    }
                 }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};