class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // require concept of previous small pse and next smaller nse
        stack<int>st;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && heights[i]<heights[st.top()]){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int idx=st.top();
                    st.pop();
                     ans=max(ans,heights[idx]*(i-(!st.empty()?st.top():-1) -1));
                }
            }
                st.push(i);
        }

         while(!st.empty()){
                    int idx=st.top();
                    st.pop();
                     ans=max(ans,heights[idx]*(n-(!st.empty()?st.top():-1) -1));
                }

                return ans;
    }
};