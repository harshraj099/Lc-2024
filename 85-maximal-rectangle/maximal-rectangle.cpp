class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
         int maxArea = 0;
         int n=matrix.size(),m=matrix[0].size();
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
    // histogram method to find min height

      for(int i=0;i<m;i++){
        // int mini=1e9;
        // or                           //note
        for(int j=i,mini=1e9;j<m;j++){ //yaha mini 1 hi bar initialise ho raha hai 
            mini=min(mini,height[j]);  // bar bar nahi 
            int area=mini*(j-i+1);
            maxArea=max(maxArea,area);
        }
      }
       
    }
    return maxArea;
    }
};