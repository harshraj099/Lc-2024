class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
       vector<pair<int,int>>adj[n+1];
       for(auto it:times){
        adj[it[0]].push_back({it[1],it[2]});
       }
       
    //    vector<int>vis(n+1,0);
    //    vis[0]=1;
       vector<int>dist(n+1,1e9);

        int maxi=0;
        queue<pair<int,int>>q;

        q.push({k,0});  // node , time 
        // vis[k]=1;
        dist[k]=0;
        dist[0]=0;
        // int ct=0;
        while (!q.empty()){
            int node =q.front().first;
            int time=q.front().second;
            maxi=max(maxi,time);
            // ct++;
            q.pop();
            // cout<<maxi;
            for(auto it:adj[node]){
                // vis[it.first]=1;
                if(time+it.second<dist[it.first]){
                    dist[it.first]=time+it.second;
                    q.push({it.first,dist[it.first]});
                }
            }
        }

        int ans=*max_element(dist.begin(),dist.end());
        if(ans>=1e9)return -1;
        return ans;
    }
};