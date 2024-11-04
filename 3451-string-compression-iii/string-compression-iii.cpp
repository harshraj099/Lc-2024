class Solution {
public:
    string compressedString(string word) {
     
        int  n=word.size();
    string comp="";
   int ct=1;
    for(int i=1;i<n;i++){
        if(word[i]==word[i-1] && ct<9){
            ct++;
        }
        else{
            comp+=to_string(ct);
            comp+=word[i-1];
            ct=1;
        }
    }
    if(ct>0){
        comp+=to_string(ct);
        comp+=word[n-1];
    }
    return comp;

    }
};