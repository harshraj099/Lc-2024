class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)return {0};
        queue<int>q; //node,lavel
        int k=edges.size(),m=edges[0].size();
        vector<int>adj[n];
        for(int i=0;i<k;i++){
                adj[edges[i][0]].push_back(edges[i][1]);
                 adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>indg(n,0);
        for(int i=0;i<n;i++)
        { for(auto it:adj[i]){
                  indg[it]++;
                }
        }
                for(int i=0;i<n;i++){
                    if(indg[i]==1){q.push(i);
                    }
                }
                    vector<int>v;
            while(!q.empty()){
                int size=q.size();
                v.clear();
               while(size--){
                long long node=q.front();
                q.pop();
                v.push_back(node);
                for(auto it:adj[node]){
                     indg[it]--;  
                    if(indg[it]==1)q.push(it);        
                }
                }
       }
        return v;

    }
};