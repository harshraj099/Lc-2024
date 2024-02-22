class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indgree(n+1,0);
         vector<int>outdegree(n+1,0);
        indgree[0]=1;
        outdegree[0]=1;
        for(auto it:trust){
            int u=it[0];
            int v=it[1];
            indgree[v]++;
            outdegree[u]++;
        }
        for(int i=0;i<n+1;i++){
            if(indgree[i]==n-1 && outdegree[i]==0)return i;
        }
        return -1;
    }
};