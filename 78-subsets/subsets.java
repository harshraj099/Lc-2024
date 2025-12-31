class Solution {
    void f(int i,int n,int []nums,List<Integer>v,List<List<Integer>>ans){
        if(i==n){
            ans.add(new ArrayList<>(v));
            return;
        }

        // take
        v.add(nums[i]);
        f(i+1,n,nums,v,ans);
        v.remove(v.size()-1);

        // not take
         f(i+1,n,nums,v,ans);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>>ans=new ArrayList<>();
        int n=nums.length;
        List<Integer>v=new ArrayList<>();
        f(0,n,nums,v,ans);
        return ans;
    }
}