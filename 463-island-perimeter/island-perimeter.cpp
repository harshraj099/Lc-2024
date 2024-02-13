class Solution {
public:
    vector<pair<int,int>>rc={{0,-1},{1,0},{0,1},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fl=0;
              int n=grid.size();
        int m=grid[0].size();
                vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    fl=1;
                    vis[i][j]=1;
                    break;
                }
            }
            if(fl)break;
        }
  
        int sum=0;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            // vis[row][col]=1;
            q.pop();
            int ct=4;
            for(int i=0;i<4;i++){
                int r=row+rc[i].first;
                int c=col+rc[i].second;
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 &&!vis[r][c]){
                    ct--;
                    vis[r][c]=1;
                    q.push({r,c});
                }
                  else if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]){
                    ct--;
                }
            }
            sum+=ct;
        }
        return sum;
    }
};