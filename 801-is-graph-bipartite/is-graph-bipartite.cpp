class Solution {
public:
    bool f(int node,vector<vector<int>>& graph,int color, vector<pair<int,int>>&vis){

        for(auto it:graph[node]){
            if(vis[it].first==0){
                vis[it].first=1;
                vis[it].second=!color;
                if(!f(it,graph,!color,vis))return false;
            }
          else if(vis[it].first!=0 && vis[it].second==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<pair<int,int>>vis(graph.size(),{0,0});
         for(int i=0;i<graph.size();i++){
            if(vis[i].first==0){
                vis[i]={1,0};
            if(!f(i,graph,0,vis))return false;
            }
         }
        return true;
    }
};