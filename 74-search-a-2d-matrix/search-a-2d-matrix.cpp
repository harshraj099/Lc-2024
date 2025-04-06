class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int left=0,right=r*c-1;

        while(left<=right){
            int mid=(right+left)/2;
            int row=mid/c;
            int col=mid%c;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target){
                left=mid+1;
            }
            else {
                right=mid-1;
                }
        }

        return false;
    }
};