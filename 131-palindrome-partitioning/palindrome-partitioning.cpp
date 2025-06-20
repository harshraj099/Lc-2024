class Solution {
public: 
      bool  ispalindrome(string s){
            int i=0,r=s.size()-1;
            while(i<r){
                if(s[i]!=s[r])return false;
                i++;
                r--;
            }
            return true;
        }
      void f(int i,string s,int n, vector<string> v,vector<vector<string>>&res){
        if(i==n){
             res.push_back(v);
            return;
        }
        
        for(int idx=i;idx<n;idx++){
            string st = s.substr(i, idx - i + 1);
            if(ispalindrome(st)){
            v.push_back(st);
            f(idx+1,s,n,v,res);
            v.pop_back();
            }
        }

        
    }
    vector<vector<string>> partition(string s) {
         int n=s.size();
        vector<vector<string>>res;
        vector<string> v;
        f(0,s,n,v,res);
        return res;
    }
};