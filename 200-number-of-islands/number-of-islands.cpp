class Solution {
public:
           queue<pair<int,int>>q;
    void bfs( vector<vector<int>>&vis,int i,int j,vector<vector<char>>& grid,int n,int m){
        vis[i][j]=1;
     
        // q.push({i,j});
        // while(!q.empty()){
        //     i=q.front().first;
        //     j=q.front().second;
        //     q.pop();
            if(i+1<n && grid[i+1][j]=='1' && !vis[i+1][j]  ){
                // q.push({i+1,j});
                // vis[i+1][j]=1;
                bfs(vis,i+1,j,grid,n,m);
            }
            if(i-1>=0 && grid[i-1][j]=='1' && !vis[i-1][j] ){
                //  q.push({i-1,j});
                // vis[i-1][j]=1;
                bfs(vis,i-1,j,grid,n,m);
            }
           if(j+1<m && grid[i][j+1]=='1' && !vis[i][j+1] ){
                //  q.push({i,j+1});
                // vis[i][j+1]=1;
                bfs(vis,i,j+1,grid,n,m);
            }
             if(j-1>=0 && grid[i][j-1]=='1' && !vis[i][j-1] ){
                //  q.push({i,j-1});
                // vis[i][j-1]=1;
                bfs(vis,i,j-1,grid,n,m);
            }

        // }
        // return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ct++;
                    bfs(vis,i,j,grid,n,m);
                }
            }
        }
        return ct;
    }
};