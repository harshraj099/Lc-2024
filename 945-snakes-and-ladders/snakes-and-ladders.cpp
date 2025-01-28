class Solution {
public:
   
    int snakesAndLadders(vector<vector<int>>& board) {
         int n = board.size();
        vector<int> dist(n*n+1,-1);

        queue<int>q;
        q.push(1);
        dist[1]=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            if(curr==n*n)return dist[curr];

            for(int i=1;i<=6;i++){
                int next=curr+i;

                if(next>n*n)continue;

                  int r=(next-1)/n;
                 int c=(next-1)%n;
                  if(r%2==1){
                     c=n-1-c;
                  }
                    r=n-1-r;
                 if(board[r][c]!=-1){
                    next=board[r][c];
           }
          if(dist[next]==-1){
            dist[next]=dist[curr]+1;
            q.push(next);
          }
            }
        }  
         return -1; 
    }
};