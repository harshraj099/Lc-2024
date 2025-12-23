class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        
        // using sign fliping as total no equal to indices
        // if duplicate i,e no. is already reached and must be a -ve
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                res.add(idx + 1);
            }

            nums[idx] = -nums[idx];
        }

        return res;
    }
}
