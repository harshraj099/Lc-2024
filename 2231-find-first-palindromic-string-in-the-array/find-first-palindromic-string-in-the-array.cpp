class Solution {
public:
    bool check(string s,int left,int right){
        int fl=0;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else if(s[left]!=s[right]){
                fl=1;
                break;
            }
        }
        if(fl)return false;
        else return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string s=words[i];
            if(check(s,0,s.size()-1))return s;
        }
        return "";
    }
};