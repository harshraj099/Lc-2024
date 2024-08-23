class Solution {
public:
vector<pair<int,int>>dirc={{0,1},{0,-1},{1,0},{-1,0}};
    void f(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&mat,int n,int m){
        vis[i][j]=1;
        // cout<<i<<" "<<j<<endl;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]==1){
                // vis[r][c]=1;
        // cout<<r<<" "<<c<<endl;
                f(r,c,vis,mat,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                // vis[0][j]=1;
                f(0,j,vis,grid,n,m);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                // vis[n-1][j]=1;
                f(n-1,j,vis,grid,n,m);
            }
        }
        // col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                // vis[i][0]=1;
                f(i,0,vis,grid,n,m);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                // vis[i][m-1]=1;
                f(i,m-1,vis,grid,n,m);
            }
        }
        int ct=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && !vis[i][j]) ct++;
            }
        }
        return ct;
    }
};