class Solution {
public:
        vector<pair<int,int>>dirc={{0,1},{0,-1},{1,0},{-1,0}};
         vector<vector<int>> solve(vector<vector<int>>&vis,vector<vector<int>>&mat,int n,int m,queue<pair<int,pair<int,int>>>&q){
            vector<vector<int>> ans(n,vector<int>(m,0));
            while(!q.empty()){
                 int dist=q.front().first;
                    int i=q.front().second.first;
                    int j=q.front().second.second;
                q.pop();
                ans[i][j]=dist;
                for(auto it:dirc){
                    int r=i+it.first;
                    int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c]==1){
                vis[r][c]=1;
                q.push({dist+1,{r,c}});
            }
                }
            }
            return ans;
         }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           int n=mat.size();
	    int m=mat[0].size();
         queue<pair<int,pair<int,int>>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mat[i][j]==0){
                q.push({0,{i,j}});
	        //    vis[i][j]=1;
	            }
	        }
	    }
	  return solve(vis,mat,n,m,q);
    }
};