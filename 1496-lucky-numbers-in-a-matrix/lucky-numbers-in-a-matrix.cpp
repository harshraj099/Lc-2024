class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            int mini=*min_element(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<m;j++){
            if(matrix[i][j]==mini){
                int maxi=0;
                for(int k=0;k<n;k++){
                    if(matrix[k][j]>maxi)maxi=matrix[k][j];
                }
     if(maxi==mini)ans.push_back(mini);
     break;
                }
            }
        }
    return ans;
    }
};