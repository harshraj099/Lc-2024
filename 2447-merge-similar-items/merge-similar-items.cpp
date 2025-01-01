class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>>ret;
        
        map<int,int>s;

        for( auto it:items1){

            s.insert({it[0],it[1]});
        }
        for( auto it:items2){
            if(s[it[0]]){
                s[it[0]]+=it[1];
            // cout<<it[0]<<" "<<s[it[0]]<<endl;
            }
            else {
                s[it[0]]=it[1];
                // ({it[0],it[1]});
                // cout<<it[1];
            }
        }
        for(auto it:s){
            vector<int>temp;

            temp.push_back(it.first);
            temp.push_back(it.second);

            ret.push_back(temp);
        }
        return ret;
    }
};