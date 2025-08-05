class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         map<int,int>m;
        stack<int>st;
        for(int i=0;i<2*nums.size();i++){
            int j=i%nums.size();
            while(!st.empty() && nums[st.top()]<nums[j]){
              if(m.find(st.top())==m.end()) m[st.top()]=nums[j];
                st.pop();
            }
            st.push(j);
        }
        while(!st.empty()){
         if(m.find(st.top())==m.end())   m[st.top()]=-1;
            st.pop();
        }

        for(int i=0;i<nums.size();i++){
            nums[i]=m[i];
        }
        return nums;
    }
};