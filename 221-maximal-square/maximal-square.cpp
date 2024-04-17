class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>height(m,0);
        int max_area=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            for(int k=0;k<m;k++){
                int mini=1e9;
                for(int p=k;p<m;p++){
                    mini=min(mini,height[p]);
                    int area=0;
                   if((p-k+1)==mini) area=(p-k+1)*mini;
                    max_area=max(area,max_area);
                }
            }
        }
     return max_area;
    }
};