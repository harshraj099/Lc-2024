class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // go right , down , left , up
        vector<int> res;
        int i=0,j=0;
        while(true){
            // right
            while(j<m && matrix[i][j]!=-1e5){
                res.push_back(matrix[i][j]);
                matrix[i][j]=-1e5;
                j++;
            }
            j=j-1;
            i=i+1;
            // down
            while(i<n && matrix[i][j]!=-1e5){
                res.push_back(matrix[i][j]);
                matrix[i][j]=-1e5;
                i++;
            }
            i=i-1;
            j=j-1;
            // left
            while(j>=0 && matrix[i][j]!=-1e5){
                res.push_back(matrix[i][j]);
                matrix[i][j]=-1e5;
                j--;
            }
            j=j+1;
            i=i-1;
            // up
            while(i>=0 && matrix[i][j]!=-1e5){
                res.push_back(matrix[i][j]);
                matrix[i][j]=-1e5;
                i--;
            }
            i=i+1;
            j=j+1;
            if(res.size()==n*m)break;
        }

        return res;
    }
};