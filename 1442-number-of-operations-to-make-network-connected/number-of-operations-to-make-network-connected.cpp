class disjoint{
        public:
        vector<int>rank,parent,size;
        // constructor
        disjoint(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        
        // find ultimate parent
       int  find_ulp(int x){
            if(parent[x]==x)return parent[x];
            return parent[x]=find_ulp(parent[x]);
        }
        
        // union by rank
        
       void union_by_rank(int x,int y)
       {
            int u=find_ulp(x);
            int v=find_ulp(y);
            
            if(u==v)return;
            
            if(rank[u]>rank[v])
            {
                parent[v]=u;
            }
           else if(rank[u]<rank[v])
               {
                    parent[u]=v;
                }
            else {
              parent[u]=v;
              rank[v]++;
            }
        }
        
        void union_by_size(int x,int y){
            int u=find_ulp(x);
            int v=find_ulp(y);
            
            if(u==v)return;
            
            if(size[u]>size[v]){
                parent[v]=u;
                size[u]+=size[v];
            }
            else {
            parent[u]=v;
            size[v]+=size[u];
            } 
        }
    };

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int ct=0;        
        int connect=0;
        disjoint ds(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            int par_u=ds.find_ulp(u);
            int par_v=ds.find_ulp(v);
            
            if(par_u!=par_v){
                ds.union_by_size(u,v);
            }
            else ct++;
        }
        for(int i=0;i<n;i++){
            int x=ds.find_ulp(i);
             if(x==i){
                connect++;
            }
        }
        if(ct>=connect-1)return connect-1;
        return -1;
    }
};