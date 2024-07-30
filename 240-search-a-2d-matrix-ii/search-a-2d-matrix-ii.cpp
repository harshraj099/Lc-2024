class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
           int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int low=0;
            int high=m-1;
            if( target>matrix[i][high])continue;
            else{
                int mid;
                while(low<=high){
                    mid=(low+high)/2;
                    if(matrix[i][mid]==target)return true;
                    if(matrix[i][mid]<target)low=mid+1;
                    else high=mid-1;
                }
            }
        }
        return false;
    }
};