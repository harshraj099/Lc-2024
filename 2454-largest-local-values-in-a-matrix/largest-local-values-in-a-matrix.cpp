class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
         vector<vector<int>>ans(n-2,vector<int>(m-2));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                ans[i-1][j-1]=grid[i][j];
                for(int r=i-1;r<=i+1;r++){
                    for(int c=j-1;c<=j+1;c++){
                   ans[i-1][j-1]=max(ans[i-1][j-1],grid[r][c]);
                    }
                }
            }
        }
return ans;
    }
};