class Solution {
public:
    void f(int idx,string digits,vector<string>&vs,vector<string>&ans,string s){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        // for(int i=idx;i<digits.size();i++){
            int n=digits[idx]-'0';
            // cout<<n<<" ";
            for(int j=0;j<vs[n].size();j++){
                string p=vs[n];
                f(idx+1,digits,vs,ans,s+p[j]); 
            }
        // }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return{};
        vector<string>vs={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        f(0,digits,vs,ans,"");
        return ans;
    }
};