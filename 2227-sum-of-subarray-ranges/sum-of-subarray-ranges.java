class Solution {
    public long subArrayRanges(int[] nums) {
        int n=nums.length;
        int []left=new int[n];
        int []right=new int[n];

        // next largest
        Stack<int []>st=new Stack<>();
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && st.peek()[0]<=nums[i]){
                right[st.peek()[1]]=i;
                st.pop();
            }
            st.push(new int[]{nums[i],i});
        }
       while(!st.isEmpty()){
                right[st.peek()[1]]=n;
                st.pop();
            }

        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && st.peek()[0]<nums[i]){
                left[st.peek()[1]]=i;
                st.pop();
            }
           st.push(new int[]{nums[i],i});
        }
         while(!st.isEmpty()){
                left[st.peek()[1]]=-1;
                st.pop();
            }

            // next smallest
             int []leftS=new int[n];
            int []rightS=new int[n];
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && st.peek()[0]>=nums[i]){
                rightS[st.peek()[1]]=i;
                st.pop();
            }
           st.push(new int[]{nums[i],i});
        }
       while(!st.isEmpty()){
                rightS[st.peek()[1]]=n;
                st.pop();
            }

        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && st.peek()[0]>nums[i]){
                leftS[st.peek()[1]]=i;
                st.pop();
            }
          st.push(new int[]{nums[i],i});
        }
         while(!st.isEmpty()){
                leftS[st.peek()[1]]=-1;
                st.pop();
            }

            long ans=0;
            for(int i=0;i<n;i++){
                long sum=(long)(right[i]-i)*(i-left[i])*nums[i]-(long)(rightS[i]-i)*(i-leftS[i])*nums[i];
                ans+=sum;
            }

            return ans;
    }
}