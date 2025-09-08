class Solution {
public:
    void f(int col,int n,vector<int>&leftrow,vector<int>lowerDiag,vector<int>upperDiag, vector<vector<string>>&ans, vector<string>&board){
        if(col==n){
            ans.push_back(board);
            return;}

        for(int i=0;i<n;i++){  // rows
        if(!leftrow[i] && !lowerDiag[i+col] && !upperDiag[n-1+col-i]){
            leftrow[i]=1;
            lowerDiag[i+col]=1;
            upperDiag[n-1+col-i]=1;
            board[i][col]='Q';
            f(col+1,n,leftrow,lowerDiag,upperDiag,ans,board);
             leftrow[i]=0;
            lowerDiag[i+col]=0;
            upperDiag[n-1+col-i]=0;
            board[i][col]='.';
        }
        }
        }
    vector<vector<string>> solveNQueens(int n) {
        // maintain a left row , lower diagnal and upper diagonal
        // \,/ , - 
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int>leftrow(n,0),lowerDiag(2*n-1,0),upperDiag(2*n-1,0);
        f(0,n,leftrow,lowerDiag,upperDiag,ans,board);
        return ans;
    }
};