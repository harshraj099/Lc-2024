class Solution {
public:
        vector<pair<int,int>>dirc={{0,1},{1,0}};
        void f(int i,int j,vector<vector<int>>& land,vector<vector<int>>&vis,int &x,int &y){

            for(auto it:dirc){
                int r=i+it.first;
                int c=j+it.second;
            if(r<land.size() && c<land[0].size() && !vis[r][c] && land[r][c]==1){
                vis[r][c]=1;
                x=max(x,r);
                y=max(y,c);
                f(r,c,land,vis,x,y);
            }
            }
            return;
        }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
         vector<vector<int>> ans;
         int n=land.size();
         int m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)); 
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    vector<int>vec;
                    vec.push_back(i);
                    vec.push_back(j);
                    int x=i,y=j;
                    f(i,j,land,vis,x,y);
                    // cout<<x<<" "<<y<<endl;
                       vec.push_back(x);
                    vec.push_back(y);
                    ans.push_back(vec);
                }
            }
    }
    return ans;
    }
};