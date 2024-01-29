class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        // vector<int>vis(n+1,0);
        vector<int>dist(n+1,1e9);
        dist[0]=-1;
        queue<pair<int,int>>q;
        q.push({k,0});
        dist[k]=0;
        int ct=0;
        int maxi=INT_MIN;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            // ct++;     
            for(auto it:adj[node]){ 
          if(time+it.second<dist[it.first])
          {dist[it.first]=time+it.second;
         q.push({it.first,it.second+time});}
                    }
        }
        // cout<<ct;
    long long ans=*max_element(dist.begin(),dist.end());
        if(ans>=1e9)return -1;
        else return ans;
    }
};