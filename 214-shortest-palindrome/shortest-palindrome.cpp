class Solution {
public:
    string shortestPalindrome(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        string srev=temp;
    //    sincev using kmp algo
       string kmp =s+"*"+srev;
    //  using lps = longest palindromic subsequence
    int n=kmp.size();
    vector<int>lps(n,0);
    int prev=0,i=1;
    lps[0]=0;

    while(i<n){
        if(kmp[prev]==kmp[i]){
            lps[i]=prev+1;
            prev+=1;
            i+=1;
        }
        else if(prev==0){
            lps[i]=0;
            i+=1;
        }
        else {
            prev=lps[prev-1];
        }
    }
    int len=lps[n-1];

    string ans = srev.substr(0, s.size() - len) + s;

    return ans;
    }
};