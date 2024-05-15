class Solution {
public:
    vector<pair<int,int>>dirc={{-1,0},{0,1},{1,0},{0,-1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>temp(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q; //score,row,col
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]==1){q.push({0,{i,j}});
            temp[i][j]=0;
            }
            }
        }
        while(!q.empty()){
            int score=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
              q.pop();
            for(auto it:dirc){
                int r=row+it.first;
                int c=col+it.second;
                int scr=score+abs(row-r)+abs(col-c);
                if(r>=0 && r<n && c>=0 && c<n && temp[r][c]>scr){
                    temp[r][c]=scr;
                    q.push({scr,{r,c}});
                }
            }
        }
    

    vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({temp[0][0],{0,0}});
        vis[0][0]=1;
        int mini=1e9;
        while(!pq.empty()){
            int score=pq.top().first;
             int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            mini=min(mini,score);

            if(row==n-1 && col==n-1)break;
             for(auto it:dirc){
                int r=row+it.first;
                int c=col+it.second;
                if(r>=0 && r<n && c>=0 && c<n && !vis[r][c]){
                    vis[r][c]=1;
                    pq.push({temp[r][c],{r,c}});
                }
            }
        }  

        return mini;
    }
};