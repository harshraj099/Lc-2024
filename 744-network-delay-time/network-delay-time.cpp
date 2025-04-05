class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
       vector<pair<int,int>>adj[n+1];
       for(auto it:times){
        adj[it[0]].push_back({it[1],it[2]});
       }
       vector<int>dist(n+1,1e9);

        // int maxi=0;
        // queue<pair<int,int>>q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0,k});  // node , time 
        dist[k]=0;
        dist[0]=0;
        while (!q.empty()){
            int time =q.top().first;
            int node=q.top().second;
            // maxi=max(maxi,time);
            q.pop();
            for(auto it:adj[node]){
                if(time+it.second<dist[it.first]){
                    dist[it.first]=time+it.second;
                    q.push({dist[it.first],it.first});
                }
            }
        }

        int ans=*max_element(dist.begin(),dist.end());
        if(ans>=1e9)return -1;
        return ans;
    }
};