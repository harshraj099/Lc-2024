class Solution {
public:
    vector<pair<int,int>>dirc={{1,0},{0,1},{-1,0},{0,-1}};
    void f(int i,int j,vector<vector<int>>& image,int n,int m,int color,int prevColor){
        image[i][j]=color;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && image[r][c]==prevColor){
                f(r,c,image,n,m,color,prevColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(color==image[sr][sc])return image;
        f(sr,sc,image,n,m,color,image[sr][sc]);
        return image;
    }
};