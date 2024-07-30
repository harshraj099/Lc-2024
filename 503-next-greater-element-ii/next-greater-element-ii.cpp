class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // it is circular or we can consider it as 2*n size nums
        //or traverse nums twice
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,-1); 
        for(int i=2*n-1;i>=0;i--){
           while(!st.empty() && st.top()<=nums[i%n])st.pop();
            if(i<n){
        //    while(!st.empty() && st.top()<=nums[i%n])st.pop();
                if(!st.empty())ans[i%n]=st.top();
            }

            st.push(nums[i%n]);
        }
        return ans;
    }
};