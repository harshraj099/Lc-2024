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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint ds(n);
        map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else {
                    ds.union_by_size( m[accounts[i][j]],i);
                }
            }
        }

        vector<string>store[n];
            for(auto it:m){
                string mail=it.first;
                int idx=it.second;
                int node=ds.find_ulp(idx);
                store[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++){
        vector<string>temp;
        string name= accounts[i][0];
        if(!store[i].size())continue;
        temp.push_back(name);
        for(auto it:store[i]){
        temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
    }
};