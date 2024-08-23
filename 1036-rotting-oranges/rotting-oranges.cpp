class Solution {
public:
    vector<pair<int,int>>dirc={{0,-1},{-1,0},{0,1},{1,0}};
    int f(queue<pair<int,pair<int,int>>>&q,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&vis){
        int max_time=0;
        while(!q.empty()){
            int time =q.front().first;
            int i =q.front().second.first;
            int j =q.front().second.second;
            max_time=max(max_time,time);
            q.pop();
          for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==1){
                grid[r][c]=2;
                vis[r][c]=1;
                q.push({time+1,{r,c}});
            }
        }
        }
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]==1){
                   return -1;
                 }
            }
        }
        return max_time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        int time=0,max_time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                 }
            }
        }
   return f(q,n,m,grid,vis);
    }
};