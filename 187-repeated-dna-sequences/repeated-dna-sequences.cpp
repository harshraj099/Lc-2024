class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       map<string,int>m;
        string ss="";
        for(int i=0;i<10;i++)ss+=s[i];
        m[ss]++;
       int left=1,right=10;
       while(right<s.size()){
           ss.erase(ss.begin(),ss.begin()+1);
        //    cout<<ss<<" ";
            ss+=s[right];
            //   cout<<ss<<endl;
            m[ss]++;
            left++;
            right++;
       }
        vector<string> v;
       for(auto it:m){
           if(it.second>1)v.push_back(it.first);
       }
       return v;
    }
};