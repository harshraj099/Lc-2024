class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=1;
        int n=height.size();
        int  trap=0;
        while(l<=r && r<n){
            if(height[r]<height[l]){
                trap+=(height[l]-height[r]);
                r++;
            }
            else {
                l=r;
                r++;
            }
        }
        if(l!=n-1){
            int a=n-1,b=n-2;
            trap-=height[l]-height[a];
              while(b>l){
              trap-=height[l]-height[b];

               if(height[b]<height[a]){
                trap+=height[a]-height[b];
                b--;
            }
            else {
                a=b;
                b--;
            }
              }
        }
        return trap;
    }
};