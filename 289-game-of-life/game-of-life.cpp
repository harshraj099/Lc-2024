class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>tmp=board;
        vector<pair<int,int>>dirc={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ones=0,zeros=0;
                for(auto it:dirc){
                    int r=i+it.first;
                    int c=j+it.second;
                    if(r>=0 && r<n && c>=0 && c<m){
                        if(board[r][c]==0)zeros++;
                        else ones++;
                    }
                }
                //cout<<zeros<< " "<<ones<<endl;
                if(board[i][j]==1 && ones<2)tmp[i][j]=0;
               else if(board[i][j]==1 && ones>=2 && ones<=3)tmp[i][j]=board[i][j];
               else if(board[i][j]==1 && ones>3)tmp[i][j]=0;
               else if(board[i][j]==0 && ones==3)tmp[i][j]=1;
            }
        }

        board=tmp;
    }
};