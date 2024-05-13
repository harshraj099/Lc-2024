class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=(1<<(m-1))*n;
        for(int j=1;j<m;j++){
            int ct=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==grid[i][0])ct++;
                // 0th row wale se check kero match ker raha hai ya nahi
            }
            ans+=(1<<(m-1-j))*max(n-ct,ct);
        }
        return ans;
    }
};