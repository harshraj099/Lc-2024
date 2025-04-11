class Solution {
public:
    vector<pair<int ,int >>dirc={{0,1},{1,0},{-1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
    std::priority_queue<
        std::pair<int, std::pair<int, int>>,
        std::vector<std::pair<int, std::pair<int, int>>>,
        std::greater<std::pair<int, std::pair<int, int>>>
    > pq;
    pq.push({grid[0][0],{0,0}});
    vis[0][0]=1;
    while(!pq.empty()){
        int node=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        // vis[i][j]=1;
        if(i==n-1 && j==n-1)return node;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<n && !vis[r][c]){
                 vis[r][c]=1;
                if(grid[r][c]<=node) pq.push({node,{r,c}});
              else pq.push({grid[r][c],{r,c}});
            }
        }
    }
    return -1;
    }
};