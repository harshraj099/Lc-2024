class disjoint{
    public:
    vector<int>par,size;
    disjoint(int n){
        par.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int x){
        if(par[x]==x)return x;
        return find(par[x]);
    }
    
    // join by size
    void join(int u,int v){
        if(u<v){
            par[u]=v;
            size[v]+=size[u];
        }
        else if(u>v){
            par[v]=u;
            size[u]+=size[v];
        }
        else {
            par[u]=v;
            size[v]+=size[u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        disjoint dj(n);
        int left=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            int u_par=dj.find(u);
            int v_par=dj.find(v);

            if(u_par==v_par)left++;
            else {
                vis[u]=1;
                vis[v]=1;
                dj.join(u_par,v_par);
            }
        }
        int ct=-1; // ek to hoga hi jo pure graph ko conect kerega
        for(int i=0;i<n;i++){
           if(dj.find(i)==i)ct++;
        }
        if(ct>left)return -1;
        return ct;
    }
};