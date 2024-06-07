class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<int>list;
        set<string>s;
        for(auto it:dictionary){s.insert(it);
        list.insert(it.size());
        }

        string ans="";
        string temp="";
        for(int i=0;i<sentence.size();i++){
             if(sentence[i]!=' ')temp+=sentence[i];
            else {
                int fl=0;
            for(auto it:list){
                int n=it;
                if(temp.size()<n){
                    ans+=temp;
                    fl=1;
                break;}
                else {
                    string st=temp.substr(0,n);
                    // cout<<st<<endl;
                    if(s.find(st)!=s.end()){
                        ans+=st;
                        fl=1;
                    break;}
                    
                }
            }
            if(!fl)ans+=temp;
                temp="";
                ans+=' ';
            }
        }
           
                int fl=0;
            for(auto it:list){
                int n=it;
                if(temp.size()<n){
                    ans+=temp;
                    fl=1;
                break;}
                else {
                    string st=temp.substr(0,n);
                    // cout<<st<<endl;
                    if(s.find(st)!=s.end()){
                        ans+=st;
                        fl=1;
                    break;}
                    
                }
            }
            if(!fl)ans+=temp;
        

                return ans;
    }
};