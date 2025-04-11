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
    vector<pair<int,int>>dirc={{0,1},{1,0},{-1,0},{0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        disjoint dj(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vis[i][j]=1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(auto it:dirc){
                            int row=r+it.first;
                            int col=c+it.second;
                            if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]){
                                vis[row][col]=1;
                                int u=dj.find(r*n+c);
                                int v=dj.find(row*n+col);
                                dj.join(u,v);
                                q.push({row,col});
                            }
                        }
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum=1;
                       set<int>s;
                    for(auto it:dirc){
                        int row=i+it.first;
                         int col=j+it.second;  
                     if(row>=0 && row<n && col>=0 && col<n  && grid[row][col]==1){
                                int par=dj.find(row*n+col);
                                if(s.find(par)!=s.end())continue;
                               int size=dj.size[par];
                               sum+=size;
                               s.insert(par);
                            }    
                    }
                    ans=max(ans,sum);
                }
            }
        }

        if(ans==0)return n*n;
        return ans;
    }
};