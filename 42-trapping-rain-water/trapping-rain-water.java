class Solution {
    public int trap(int[] height) {
        // concept of right and left max
        int leftMax=height[0];
        int rightMax=height[height.length-1];
        int water=0;
        int l=0,r=height.length-1;

        while(l<=r){
            if(leftMax<rightMax){
                leftMax=Math.max(leftMax,height[l]);
                water+=leftMax-height[l];   //left boundary - current tower , obviously right is greater so water is stored
                l++;
            }
            else{
                rightMax=Math.max(rightMax,height[r]);
                water+=rightMax-height[r];  
                r--;
            }
        }

        return water;
    }
}