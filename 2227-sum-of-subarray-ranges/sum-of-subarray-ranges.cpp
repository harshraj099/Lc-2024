class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        // nse
         stack<int>st;
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
             while(!st2.empty() && arr[st2.top()]>=arr[i]){  //one one side consider if repeated
                st2.pop();
            }
          right[i]=st2.empty()?n:st2.top();
           st2.push(i);
        }

        // nge
         stack<int>s;
        vector<int>leftLarge(n),rightLarge(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i]){
                s.pop();
            }
            leftLarge[i]=s.empty()?-1:s.top();
           s.push(i);
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--){
             while(!s2.empty() && arr[s2.top()]<=arr[i]){  //one one side consider if repeated
                s2.pop();
            }
          rightLarge[i]=s2.empty()?n:s2.top();
           s2.push(i);
        }

        long long sum=0;
        for(int i=0;i<n;i++){
            int l=i-left[i];
            int r=right[i]-i;
           int lLarge=i-leftLarge[i];
           int rLarge=rightLarge[i]-i;
           long long small=l*r*1ll*arr[i];
           long long large=lLarge*rLarge*1ll*arr[i];
            sum+=large-small;
        }
            return sum;
    }
};