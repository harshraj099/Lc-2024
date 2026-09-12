class pair{
    private int first, second;
    
    public pair(int first,int second){
        this.first=first;
        this.second=second;
    }
    public int getFirst(){
        return first;
    }
    public int getSecond(){
        return second;
    }
};
class Solution {
    public int orangesRotting(int[][] grid) {
        //bfs
        int time =0;
        int [][]dirc={{1,0},{0,1},{-1,0},{0,-1}};
        int n=grid.length;
        int m=grid[0].length;
        int [][]vis=new int[n][m];
        

        Queue<pair>q = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
                if(grid[i][j]==2){
                q.add(new pair(i,j));
                vis[i][j]=1;}
            }
        }
        while(!q.isEmpty()){
            int len=q.size();

            for(int i=0;i<len;i++){
                int r=q.peek().getFirst();
                int c=q.peek().getSecond();

                q.remove();
                for(int []it:dirc){
                    int row=r+it[0];
                    int col=c+it[1];

                    if( row>=0 && row<n && col >=0 && col<m && vis[row][col]==0 && grid[row][col]==1){
                        vis[row][col]=1;
                        grid[row][col]=2;
                        q.add(new pair(row,col));
                    }
                }
            }
             time++;
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                   return -1;
            }
        }
         }
         if(time == 0) return 0; 
        return time-1;
}
}