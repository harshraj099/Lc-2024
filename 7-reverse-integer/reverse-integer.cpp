class Solution {
public:
    int reverse(int x) {
        // cout<<INT_MAX;
    //    if(x>=INT_MAX || x<=INT_MIN)return 0;
long long ans=0;
  while(x!=0){
    int rem=x%10;
    ans=ans*10+rem;
    x=x/10;
  }
//   cout<<ans;
if(ans>=INT_MAX || ans<=INT_MIN)return 0;
return ans;
       } 
};