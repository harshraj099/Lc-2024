class Solution {
    boolean f(int idx, int[] nums, int target, ArrayList<ArrayList<Boolean>>dp){
        if(idx==nums.length)return false;
        if(target==0)return true; 

        if(dp.get(idx).get(target)!=null)return dp.get(idx).get(target);
       
        boolean take=false;
        if(target>=nums[idx])take=f(idx+1,nums, target-nums[idx],dp);

        boolean not_take=f(idx+1,nums,target,dp);

        dp.get(idx).set(target,take | not_take);

        return take | not_take;
    }
    public boolean canPartition(int[] nums) {
        int sum=Arrays.stream(nums).sum();
        if(sum%2==1)return false;
        int target=sum/2;
        ArrayList<ArrayList<Boolean>>dp=new ArrayList<>();

        for(int i=0;i<nums.length;i++){
             dp.add(new ArrayList<>(Collections.nCopies(target + 1, null)));
        }

        return f(0,nums,target,dp);
    }
}