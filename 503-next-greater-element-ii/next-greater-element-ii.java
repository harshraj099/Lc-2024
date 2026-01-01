class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        Stack<Integer>st=new Stack<>();
        int []ans=new int[n];
        for(int i=2*n-1;i>=0;i--){
            if(i<n){
               while(!st.isEmpty() && st.peek()<=nums[i]){
                st.pop();
               } 
                ans[i]=!st.isEmpty()?st.peek():-1;
            }

            st.push(nums[i%n]);
        }

        return ans;
    }
}