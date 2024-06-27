class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int prev1=edges[0][0],prev2=edges[0][1];
        for(int i=1;i<edges.size();i++){
            if(edges[i][0]==prev1|| edges[i][0]==prev2)return edges[i][0];
            if(edges[i][1]==prev1|| edges[i][1]==prev2)return edges[i][1];
        }

        return 0;
    }
};