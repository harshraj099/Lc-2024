class Solution {
public:
    vector<pair<int,int>>dirc={{-1,0},{0,1},{1,0},{0,-1}};
    void f(int r,int c,int color,int iniColor,vector<vector<int>>& image,int n,int m){

        for(auto it:dirc){
            int row =r+it.first;
            int col=c+it.second;
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==iniColor){
                image[row][col]=color;
                f(row,col,color,iniColor,image,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color)return image;
        f(sr,sc,color,image[sr][sc],image,n,m);
        image[sr][sc]=color;
        return image;

    }
};