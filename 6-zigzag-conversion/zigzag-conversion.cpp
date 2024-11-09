class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v(numRows,vector<char>(s.size(),' '));
        int idx=0,i=0,col=0;
        while(i<s.size()){
            if(idx==0){
                while(idx<numRows){
                    if(i==s.size())break;
                    v[idx][col]=s[i];
                    idx++;
                    i++;
                }
                idx--;
             if (idx>0) idx--;
                col++;
            }
            else {
               v[idx][col]=s[i]; 
               idx--;
               col++; 
               i++;
            }
        }
        //  for(int i=0;i<s.size();i++){
        //  for(int j=0;j<numRows;j++){
        //    cout<<v[j][i]<<" ";
        //  }
        //  cout<<endl;
        // }   


            string ans="";
        for(int i=0;i<numRows;i++){
         for(int j=0;j<s.size();j++){
            if(v[i][j]!=' ')ans+=v[i][j];
         }
        }

        return ans;
    }
};