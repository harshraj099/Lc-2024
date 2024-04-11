class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++)
        {
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
                }
            st.push(num[i]);
        }
        while(k>0){
           st.pop(); 
           k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans=="")return "0";
       string result;
       for(int i=0;i<ans.size();i++){
        if(ans[i]=='0')continue;
        else {result=ans.substr(i,ans.size());
        break;}
       }
       if(result=="")return "0";
        return result;
    }
};