class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
    // cout<<s[s.size()-1];
        while(s.size()>1){
            if((s[s.size()-1])=='1'){
                cnt++;
                int r=s.size()-1,fl=0;
                while(r>=0){
                    if(s[r]=='1'){
                        s[r]='0';
                    }
                    else {
                        s[r]='1';
                        fl=1;
                        break;
                    }
                    r--;
                }
                if(!fl){
                    s.insert(s.begin(),'1');
                }
                // cout<<s<<" ";
            }
            else {
                s.pop_back();
                cnt++;
            }
        }
        return cnt;
    }
};