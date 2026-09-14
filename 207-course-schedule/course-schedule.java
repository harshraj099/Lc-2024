class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int V=numCourses;
        int []indegree=new int[V];
        ArrayList<Integer>[]adj=new ArrayList[V];
        
        for(int i=0;i<V;i++){
        adj[i]=new ArrayList<>();
        }
        
        for(int[] e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[v].add(u);
            indegree[u]++;
            
        }
        
        Queue<Integer>q= new LinkedList<>();
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.add(i);
        }
        while(!q.isEmpty()){
            int num=q.peek();
            q.remove();
            
            for(int it:adj[num]){
                indegree[it]--;
                if(indegree[it]==0)q.add(it);
            }
        }
        
        for(int i=0;i<V ;i++){
            if(indegree[i]!=0)return false;
        }
        return true;
    }
}