class Solution {
public:
    string addBinary(string a, string b) {
       int cy=0;
       int i=a.length()-1,j=b.length()-1;
       string res="";
       while(i>=0 && j>=0){
        if(a[i]==b[j] && a[i]=='1'){
            if(cy==1){
                res+='1';
            }
            else{
                res+='0';
                cy=1;
            }
        }
         else if(a[i]==b[j] && a[i]=='0'){
            if(cy==1){
                res+='1';
                cy=0;
            }
            else{
                res+='0';
            }
        }
       else if(a[i]!=b[j]){
            if(cy==1){
                res+='0';
            }
            else{
                res+='1';
            }
       } 
       i--;
       j--;
    }

while(i>=0){
     if(a[i]=='1' && cy==1){
                res+='0';
        }
        else {
            if(cy==1){
                res+='1';
                cy=0;
            }
            else{
            res+=a[i];
            } 
        }
        i--;
}

while(j>=0){
     if(b[j]=='1' && cy==1){
                res+='0';
        }
        else {
            if(cy==1){
                res+='1';
                cy=0;
            }
            else{
            res+=b[j];
            } 
        }
        j--;
}

    if(cy==1)res+='1';

     reverse(res.begin(),res.end());
    return res;
    }
};