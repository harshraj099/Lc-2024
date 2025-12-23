class Solution {
    public int findMaximumXOR(int[] nums) {
            int res=0,mask=0;

            for(int i=31;i>=0;i--){

                mask=mask|1<<i;

                Set<Integer>s=new HashSet();
                for(int n:nums){
                    s.add(n&mask);
                }

                int temp=res|1<<i;
                
                for(int k:s){
                    if(s.contains(temp^k)){
                        res=temp;
                        break;
                    }
                }
            }
            return res;
    }
}