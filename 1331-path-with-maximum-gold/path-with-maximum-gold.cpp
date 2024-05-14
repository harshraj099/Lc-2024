class Solution {
public:
    vector<pair<int,int>>dirc={{-1,0},{0,1},{1,0},{0,-1}};
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m){

        // int take=0;
        int maxi=0;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]!=0 && !vis[r][c]){
                vis[r][c]=1;
              int  take=grid[i][j]+f(r,c,grid,vis,n,m);
                maxi=max(maxi,take);
            }
        }
        vis[i][j]=0;
        return max(maxi,grid[i][j]);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
             vector<vector<int>>vis(n,vector<int>(m,0));
             vis[i][j]=1;
            int res=f(i,j,grid,vis,n,m);
            mx=max(mx,res);
                }
            }
        }
        return mx;
    }
};