class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=to_string(s[i]-'a'+1);
        }
        // cout<<temp;
        int res=0;
        while(k--){
            int sum=0;
            for(int i=0;i<temp.size();i++){
                // cout<<char(temp[i])<<" ";
                int p=temp[i]-'0';
                // cout<<p;
             sum+=p;
            // cout<<sum<<" ";
            }
            temp=to_string(sum);
            res=sum;
        }
        return res;
    }
};