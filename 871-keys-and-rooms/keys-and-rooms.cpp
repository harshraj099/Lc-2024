class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        q.push(0);
        vector<int>vis(rooms.size(),0);
        vis[0]=1;
        int ct=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ct++;
            for(auto it:rooms[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        if(ct==rooms.size())return true;
        return false;
    }
};