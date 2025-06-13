class Solution {
public:

     void solve(int i,int n,vector<string>&res,string s,int ct1,int ct2){
        if(i==n){
            res.push_back(s);
            return ;
        }
        
        // take '('
        if(ct1<n/2)solve(i+1,n,res,s+'(',ct1+1,ct2);
        
        // take ')'
         if(ct1>ct2 && ct2<n/2) solve(i+1,n,res,s+')',ct1,ct2+1);
    }
    vector<string> generateParenthesis(int n) {
          vector<string>res;
        string s="";
        solve(0,2*n,res,s,0,0);
        
        return res;
    }
};