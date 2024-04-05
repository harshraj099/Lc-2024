class Solution {
public:
    string makeGood(string s) {
        int left=0,right=1;
        // int n=s.size();
        while(left<right && right<s.size()){
            if(abs(int(s[left])-int(s[right]))==32 && left-1>=0){
                s.erase(s.begin()+left,s.begin()+right+1);
                right=left;
                left--;
                // cout<<s<<" ";
                // cout<<left<<" "<<right<<endl;
                // cout<<s.size()<<endl;
            }
            else  if(abs(int(s[left])-int(s[right]))==32 && left-1<0){
                s.erase(s.begin()+left,s.begin()+right+1);
            }
            else {
                left++;
                right++;
            }
        }
        return s;
    }
};