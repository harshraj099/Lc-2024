class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
            // vector<int>v;
        for(int i=0;i<n;i++){

            int mid=max_element(mat[i].begin(),mat[i].end())-mat[i].begin();
             int left=mid-1>=0?mat[i][mid-1]:-1;
                 int right=mid+1<m?mat[i][mid+1]:-1;

                  if(left<mat[i][mid] && right<mat[i][mid]){
                     int top=i-1>=0?mat[i-1][mid]:-1;
                 int bottom=i+1<n?mat[i+1][mid]:-1;
                    if( top<mat[i][mid] && bottom<mat[i][mid]){  
                      return {i,mid};
                    }
                }


            // int low=0;
            // int high=m-1;
            // int mid;
            // while(low<=high){
            //     mid=(low+high)/2;
            //     int left=mid-1>=0?mat[i][mid-1]:-1;
            //      int right=mid+1<m?mat[i][mid+1]:-1;
            //     if(left<mat[i][mid] && right<mat[i][mid]){
            //          int top=i-1>=0?mat[i-1][mid]:-1;
            //      int bottom=i+1<n?mat[i+1][mid]:-1;
            //         if( top<mat[i][mid] && bottom<mat[i][mid]){  
            //           return {i,mid};
            //         }
            //          else low=mid+1;
            //     }
            //     else if(left<mat[i][mid] && right>mat[i][mid])low=mid+1;
            //     else if(left>mat[i][mid] && right>mat[i][mid])low=mid+1;
            //     else high=mid-1;
            // }
        }
        return {};
    }
};