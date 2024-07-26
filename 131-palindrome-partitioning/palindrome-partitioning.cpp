class Solution {
public:
// bool ispalindrome(string &s,int start,int end){
//     while(start<=end){
//         if(s[start]!=s[end])return false;
//         start++;
//         end--;
//     }
//     return true;
// }
//         void solve(int idx,int n,vector<vector<string>>&str,string &s,vector<string>&v){
//             if(idx==n){
//                     str.push_back(v);
//                 return ;
//             }
//             for(int i=idx;i<n;i++){
//         if (ispalindrome(s,idx,i)){ 
//             string p="";
//             for(int j=idx;j<=i;j++) p+=s[j];
//             v.push_back(p);
        
//             solve(i+1,n,str,s,v);
//             v.pop_back();
//         }
//             }
//         }

bool ispalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++;
        end--;
    }
    return true;
}
          void solve(int idx,int n,vector<vector<string>>&str,string &s,vector<string>&v){
            if(idx==n){
                    str.push_back(v);
                return ;
            }

     for(int i=idx;i<n;i++){
        if(ispalindrome(s,idx,i)){
            string temp="";
            for(int j=idx;j<=i;j++)temp+=s[j];
            v.push_back(temp);
            solve(i+1,n,str,s,v);
            v.pop_back();
        }
     }

        }  
    vector<vector<string>> partition(string s) {
        vector<string>v;
        vector<vector<string>>str;
        solve(0,s.size(),str,s,v);
        return str;
    }
};