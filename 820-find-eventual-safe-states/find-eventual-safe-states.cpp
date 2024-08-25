class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
	 queue<int>q;
     int n=graph.size();
	 vector<int>indegree(n,0);
     vector<int>revgraph[n];
	 for(int i=0;i<n;i++){
	 for(auto it:graph[i]){
        revgraph[it].push_back(i);
        indegree[i]++;
     }
	 }
	 for(int i=0;i<n;i++){
	     if(indegree[i]==0)q.push(i);
	 }
	 
	 while(!q.empty()){
	     int node=q.front();
	     q.pop();
	     res.push_back(node);
	     for(auto it:revgraph[node]){
	         indegree[it]--;
	         if(indegree[it]==0){
	             q.push(it);
	         }
	     }
	 }
     sort(res.begin(),res.end());
	return res;
    }
};