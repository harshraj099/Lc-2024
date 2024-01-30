class Solution {
public:
    vector<int>v;
    void dfs(int node,vector<vector<int>>&graph,vector<vector<int>>&ans){
          v.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(v);
            return;
        }
        for(auto it:graph[node]){
            dfs(it,graph,ans);
              v.pop_back();
        } 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>>ans;
    dfs(0,graph,ans);
    return ans;
    }
};