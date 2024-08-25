class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>res;
	 queue<int>q;
	 vector<int>indegree(numCourses,0);
     vector<int>adj[numCourses];
	 for(int i=0;i<prerequisites.size();i++){
	 int u=prerequisites[i][0];
	 int v=prerequisites[i][1];
     adj[v].push_back(u);
     indegree[u]++;
	 }
     int ct=0;
	 for(int i=0;i<numCourses;i++){
	     if(indegree[i]==0)q.push(i);
	 }
	 
	 while(!q.empty()){
	     int node=q.front();
	     q.pop();
	     res.push_back(node);
         ct++;
	     for(auto it:adj[node]){
	         indegree[it]--;
	         if(indegree[it]==0){
	             q.push(it);
	         }
	     }
	 }
	 if(ct==numCourses)return true;
     return false;
    }
};