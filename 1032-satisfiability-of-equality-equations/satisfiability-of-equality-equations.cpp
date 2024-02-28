class Solution {
public:
    bool dfs(vector<int>&vis,vector<int>adj[],int u,int v){
        if(u==v)return true;
        vis[u]=1;
        for(auto it:adj[u]){
            if(!vis[it] && dfs(vis,adj,it,v))return true;
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
    
        vector<int>adj[26];
        for(auto it:equations){
                    // cout<<"hi";
                    string s=it;
                    // cout<<s;
            char c1=s[0];
            char c2=s[1];
            char c4=s[3];
            if(c2=='='){
                adj[c1-'a'].push_back(c4-'a');
                adj[c4-'a'].push_back(c1-'a');

            }
        }
         for(auto it:equations){
                    // cout<<"hi";
                    string s=it;
                    // cout<<s;
            char c1=s[0];
            char c2=s[1];
            char c4=s[3];
                vector<int>vis(26,0);
            if(c2=='='){
                if(!dfs(vis,adj,c1-'a',c4-'a'))return false;
            }
           else if(c2=='!'){
                if(dfs(vis,adj,c1-'a',c4-'a'))return false;
            }
        }
        return true;
    }
};