class Solution {
public:
    vector<pair<int,int>>dirc={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int maxi=0;
        queue<pair<int,pair<int,int>>>q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2)q.push({0,{i,j}});
                }
            }

            while(!q.empty()){
                int time=q.front().first;
                int row=q.front().second.first;
                int col=q.front().second.second;
                q.pop();
                maxi=max(maxi,time);
                for(auto it:dirc){
                    int r=it.first+row;
                    int c=it.second+col;

                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({time+1,{r,c}});
                    }
                }
            }

            for(auto it:grid){
                for(auto i:it){
                    if(i==1)return -1;
                }
            }

            return maxi;
    }
};