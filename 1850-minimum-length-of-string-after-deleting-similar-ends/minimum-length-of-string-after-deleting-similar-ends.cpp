class Solution {
public:
    int minimumLength(string s) {
        int left=0,right=s.length()-1;
        cout<<s.size();
        if(s[left]!=s[right])return s.length();
        while(left<right){
            // cout<<left<<" "<<right<<endl;
            if(left+1<right && s[left]==s[right] && s[left]==s[left+1])left++;
            else if(left<right-1 && s[left]==s[right] && s[right]==s[right-1])right--;
            else if(s[left+1]==s[right-1]){
                left++;
                right--;
            }
            else {
                left++;
                right--;
                break;
            }
        }
        if(left>right)return 0;
        return right-left+1;
    }
};