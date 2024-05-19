class Solution {
public:
    vector<pair<int,int>>dirc={{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int temp=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto it:dirc){
                int r=row+it.first;
                int c=col+it.second;
            if(r>=0 && r<n &&c>=0 && c<m && image[r][c]==temp && !vis[r][c]){
                vis[r][c]=1;
                image[r][c]=color;
                q.push({r,c});
            }
            }
        }
        return image;
    }
};