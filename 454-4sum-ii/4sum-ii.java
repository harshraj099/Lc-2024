class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        
        int cnt=0;
        Map<Integer,Integer>m=new HashMap();
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                m.put(nums1[i]+nums2[j],m.getOrDefault(nums1[i]+nums2[j],0)+1);
            }
        }
        for(int i=0;i<nums3.length;i++){
            for(int j=0;j<nums4.length;j++){
                int sum=nums3[i]+nums4[j];
                if(m.containsKey(-sum))cnt+=m.get(-sum);
            }
        }
        return cnt;
    }
}