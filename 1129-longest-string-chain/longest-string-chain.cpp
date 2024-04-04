class Solution {
public:
  
bool compare(string& s1, string& s2){

    if(s1.size() != s2.size() + 1) return false;
    
    int i = 0;
    int j = 0;
    
    while(i < s1.size()){
        if(j < s2.size() && s1[i] == s2[j]){
            i ++;
            j ++;
        }
        else i ++;
    }
    if(i == s1.size() && j == s2.size()) return true;
    else return false; 
}
 static bool comp(string& s, string& t){
    return s.size() < t.size();
}
    int longestStrChain(vector<string>& words) {
        // sort(words.begin(),words.end(),comp);
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        // for(int i=n-1;i>=0;i--){
        // for(int j=0;j<i;j++){
        //     int a=words[i].size();
        //     int b=words[j].size();
        //     if(b>=a)swap(words[i],words[j]);
        // }
        // }
        // for(auto it:words)cout<<it<<" ";
            vector<int>dp(n,1);
       int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};