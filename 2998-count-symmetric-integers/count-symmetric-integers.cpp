class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ct=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==1)continue;

            if(s.size()==2){
                if(s[0]==s[1])ct++;
            }
            if(s.size()==4){
                if(s[0]+s[1]==s[2]+s[3])ct++;
            }
        }

        return ct;
    }
};