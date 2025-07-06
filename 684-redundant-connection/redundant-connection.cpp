class disjoint{
    public:
    vector<int>par,size;
    disjoint(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++)par[i]=i;
    }

    int findpar(int node){
        if(par[node]==node)return node;
        return findpar(par[node]);
    }
    // by size
    void join(int u,int v){
        if (size[u] < size[v]) swap(u, v); // ensure u is the larger set
        par[v] = u;
        size[u] += size[v];
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 2 approaches 
        //  1. use disjoint set and if both u and v already exists
        // in the set then that is the current ans 
        //  simimlarly the last existing in the disjoint se is the last input
        // 2. find the cycle in the gph mark as visited the node 
        // and travers from the end to get the ans
       int n = edges.size();
    disjoint dsu(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        if (dsu.findpar(u) == dsu.findpar(v)) return e;                 
        dsu.join(dsu.findpar(u), dsu.findpar(v));
    }
    return {};       
    }
};