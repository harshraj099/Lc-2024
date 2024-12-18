class Solution {
public:
    void joinit(int i,vector<int>graph[],vector<int>&vis){
        for(auto it:graph[i]){
            if(!vis[it]){
                cout<<it<<" ";
                vis[it]=1;
                joinit(it,graph,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>graph[n+1];

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }

        int ct=0;
        vector<int>vis(n+1,0);

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                // cout<<i<<" ";
                vis[i]=1;
                ct++;
                joinit(i,graph,vis);
            }
        }

        return ct;
    }
};