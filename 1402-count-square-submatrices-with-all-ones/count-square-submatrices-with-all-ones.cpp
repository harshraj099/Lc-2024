class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>dirc={{-1,0},{-1,-1},{0,-1}};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                int mini=1e4;
                for(auto it:dirc){
                    int r=i+it.first;
                    int c=j+it.second;
                    if(r>=0 && c>=0 ){
                        mini=min(mini,matrix[r][c]);
                    }
                    else mini=0;
                }
                matrix[i][j]=max(matrix[i][j],mini+1);
                ans+=matrix[i][j];
                // cout<<i<<" "<<j<<"->"<<matrix[i][j]<<" "<<mini<<" "<<ans<<endl;
                }
            }
        }

        return ans;
    }
};