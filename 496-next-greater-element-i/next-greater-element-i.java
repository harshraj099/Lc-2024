class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer>m=new HashMap();
        Stack<Integer>st=new Stack<>();

        for(int n:nums2){
            while(!st.isEmpty() && st.peek()<n){
                m.put(st.peek(),n);
                st.pop();
            }
            st.add(n);
        }

         while(!st.isEmpty()){
                m.put(st.peek(),-1);
                st.pop();
            }

            int[] res=new int[nums1.length];
            for(int i=0;i<nums1.length;i++){
                res[i]=m.get(nums1[i]);
            }

            return res;
    }
}