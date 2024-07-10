class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ct=0;
        for(int i=0;i<logs.size();i++){
    string s=logs[i];
    if(s=="./")continue;
    else if(s=="../"){
        if(ct>0)ct--;
        }
    else {
        ct++;
    }
        }
        return ct;
    }
};