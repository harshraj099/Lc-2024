class Solution {
public:
        vector<pair<int,int>>dirc={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           int n=mat.size();
	    int m=mat[0].size();
         vector<vector<int>>res(n,vector<int>(m,1e9));
         queue<pair<int,pair<int,int>>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){
                res[i][j]=0;
                 q.push({0,{i,j}});
                }
            }
         }
         
         while(!q.empty()){
            int ct=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            // res[i][j]=min(res[i][j],ct);
            for(auto it:dirc){
                int r=i+it.first;
                int c=j+it.second;

                if(r>=0 && r<n && c>=0  && c<m && mat[r][c]!=0 && ct+1<res[r][c]){
                    res[r][c]=ct+1;
                    q.push({ct+1,{r,c}});
                }
            }
         }

         return res;
    }
};