class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<walls.size();i++){
          vis[walls[i][0]][walls[i][1]]=2;
        }
          for(int i=0;i<guards.size();i++){
          vis[guards[i][0]][guards[i][1]]=2;
        }
        vector<pair<int,int>>dirc={{0,-1},{-1,0},{0,1},{1,0}};

         for(int i=0;i<guards.size();i++){            
            for(auto it:dirc){
                int row=it.first;
                int col=it.second;
            int r=guards[i][0];
            int c=guards[i][1];
                while(r+row>=0 && r+row<m && c+col>=0 && c+col<n && vis[r+row][c+col]<2){
                    vis[r+row][c+col]=1;
                    r=r+row;
                    c=c+col;
                }
            }
        }

        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              
                if(vis[i][j]==0){ct++;
                 }
            }
        }
        return ct;
    }
};