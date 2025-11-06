class Solution {
public:
    string countAndSay(int n) {
      string ans="1";
      n--;
      while(n--){
        string res="";
        int ct=1;
        char ch=ans[0];
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ch)ct++;
            else {
                res+=to_string(ct)+ch;
                ch=ans[i];
                ct=1;
            }
        }
        res+=to_string(ct)+ch;
        ans=res;
      }
      return ans;
    }
};