class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    //  vector<int>adj[n];
  vector<int>indegree(n,0);
     for(auto it:edges){
        int u=it[0];
        int v=it[1];
        indegree[v]++;
        // adj[u].push_back(v);
     }   

         vector<int> res;
        for(int i=0;i<n;i++)if(indegree[i]==0)res.push_back(i);

        return res;
    }
};