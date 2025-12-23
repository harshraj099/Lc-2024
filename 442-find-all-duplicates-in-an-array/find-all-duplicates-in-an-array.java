class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Map<Integer,Integer>m=new HashMap();
        List<Integer>list=new ArrayList<>();

        for(int n:nums){
            if(m.containsKey(n))list.add(n);
            m.put(n,1);
        }

        return list;
    }
}