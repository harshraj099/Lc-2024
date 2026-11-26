class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>map=new HashMap<>();

        int ct=0;
        int sum=0;
        map.put(0,1);
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(map.containsKey(sum-k)){
                ct+=map.get(sum-k);
            }
            // map.put(sum,map.getOrDefault(sum,0)+1);
            if(map.containsKey(sum)){
                map.put(sum,map.get(sum)+1);
            }
            else map.put(sum,1);
        }
        return ct;
    }
}