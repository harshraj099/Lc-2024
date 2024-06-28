class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>m;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            m[u]++;
            m[v]++;
        }
        vector<int>node(n);
        multimap<int,int>mul;
        for(auto it:m){
            int i=it.first;
            int ct=it.second;
            // mul[ct]=i;
            mul.insert({ct,i});
        }
        long long cnt=n+1-mul.size();
         for(auto it:mul){
            node[it.second]=cnt;
            cnt++;
        }

        long long sum=0;
             for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            sum+=(node[u]+node[v]);
        }

        return sum;
    }
};