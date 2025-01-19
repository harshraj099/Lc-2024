class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;

        while(l<=r){
                s[l]=tolower(s[l]);
         s[r]=tolower(s[r]);
          if(!isalnum(s[l]))l++;
         else if(!isalnum(s[r]))r--;
        else if(s[l]!=s[r])  return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};