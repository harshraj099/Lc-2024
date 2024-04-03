class Solution {
public:
    vector<pair<int,int>>dirc{{0,1},{1,0},{0,-1},{-1,0}};
    bool f(int i,int j,vector<vector<char>>& board,int n,int m,int p,int k,string word, vector<vector<int>>&vis){
        if(p==k)return true;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]==word[p] && !vis[r][c])
           {    vis[r][c]=1;
             if(f(r,c,board,n,m,p+1,k,word,vis))return true;
           }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
      int k=word.size();
      int n=board.size();
      int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
        // vector<vector<int>>vis(n,vector<int>(m,0));
                vis[i][j]=1;
                if(f(i,j,board,n,m,1,k,word,vis))return true;
            }
        }
      }
      return false;  
    }
};