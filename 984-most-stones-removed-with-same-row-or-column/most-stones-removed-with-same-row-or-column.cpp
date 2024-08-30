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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0,maxc=0;
        for(auto it:stones){
         maxr=max(maxr,it[0]);
         maxc=max(maxc,it[1]);
        }
        disjoint ds(maxr+maxc+1);
        set<int>s;
        // keep rows 1st and move the column where rows end ,check video for approach
        for(int i=0;i<n;i++){
            int u=stones[i][0];
            int v=maxr+stones[i][1]+1;
            
                ds.union_by_size(u,v);
                s.insert(u);
                s.insert(v);
        }
        int connect=0;
        for(auto it:s){
            int x=ds.find_ulp(it);
             if(x==it) connect++;
        }
        return n-connect;
    }
};