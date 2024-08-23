class Solution {
public:
   vector<pair<int,int>>dirc={{0,1},{0,-1},{1,0},{-1,0}};
    void f(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&mat,int n,int m){
        vis[i][j]=1;
        // cout<<i<<" "<<j<<endl;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]=='O'){
                // vis[r][c]=1;
        // cout<<r<<" "<<c<<endl;
                f(r,c,vis,mat,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // row
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                // vis[0][j]=1;
                f(0,j,vis,board,n,m);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                // vis[n-1][j]=1;
                f(n-1,j,vis,board,n,m);
            }
        }
        // col
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                // vis[i][0]=1;
                f(i,0,vis,board,n,m);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                // vis[i][m-1]=1;
                f(i,m-1,vis,board,n,m);
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }
        // return board;
    }
};