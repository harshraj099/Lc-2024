class Solution {
public:
    void f(int l,int r,vector<string>&ans,string s){
        if(l==0 && r==0){
            ans.push_back(s);
            return;
        }
        // l
       if(l>0){
        //         s+='(';
        // f(l-1,r,ans,s);
        // s.pop_back();
        // or
        f(l-1,r,ans,s+"(");
        }

        //r

       if(r>l){
        //         s+=')';
        // f(l,r-1,ans,s); 
        // s.pop_back();
        // or
         f(l,r-1,ans,s+")");
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         string s="";
        f(n,n,ans,s);
        return ans;
    }
};