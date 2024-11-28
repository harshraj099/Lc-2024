class Solution {
public:
    vector<pair<int,int>>dirc={{-1,0},{0,-1},{1,0},{0,1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,(vector<int>(m,0)));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        if(grid[0][0]==1)pq.push({1,{0,0}});
        else pq.push({0,{0,0}});
        vis[0][0]=1;
        
        while(!pq.empty()){
            int cnt=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1)return cnt;
            for(auto it:dirc){
                int row=x+it.first;
                int col=y+it.second;
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col]){
                vis[row][col]=1;
               if(grid[row][col]==0) pq.push({cnt,{row,col}});
               else pq.push({cnt+1,{row,col}});
                }
            }
        }
        return 0;
    }
};