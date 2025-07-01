class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        int m=1e9+7;
        int n=arr.size();
        vector<int>left(n),right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
           st.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
             while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
          right[i]=st2.empty()?n:st2.top();
           st2.push(i);
        }

        int sum=0;
        for(int i=0;i<n;i++){
            int l=i-left[i];
            int r=right[i]-i;
            // cout<<l<<" "<<r<<endl;
            sum=(sum+l*r*1ll*arr[i])%m;
        }

        return sum%m;
    }
};