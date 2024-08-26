class Solution {
public:
vector<pair<int,int>>dirc={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        if(grid[0][0]==1)return -1;
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({1,{0,0}}); // dist,i,j
        dist[0][0]=1;
        while(!q.empty()){
            int len=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
                q.pop();
                if(i==n-1 && j==n-1)return len;
            for(auto it:dirc){
                int r=i+it.first;
                int c=j+it.second;
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && 1+len<dist[r][c]){
                    q.push({len+1,{r,c}});
                    dist[r][c]=1+len;
                }
            }
        }

        return -1;
    }
};