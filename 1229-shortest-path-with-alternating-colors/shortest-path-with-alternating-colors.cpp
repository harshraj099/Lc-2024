class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n); // {neigh, color}
        for (auto& e : redEdges)
            adj[e[0]].push_back({e[1], 0}); // red = 0
        for (auto& e : blueEdges)
            adj[e[0]].push_back({e[1], 1}); // blue = 1

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> dist(n, -1);
        queue<tuple<int, int, int>> q; // node, steps, last color

        q.push({0, 0, -1}); // start from node 0, no color yet
        visited[0][0] = visited[0][1] = true;
        dist[0] = 0;

        while (!q.empty()) {
            auto [node, steps, lastColor] = q.front();
            q.pop();

            for (auto& [neigh, color] : adj[node]) {
                if (color != lastColor && !visited[neigh][color]) {
                    visited[neigh][color] = true;
                    if (dist[neigh] == -1) dist[neigh] = steps + 1;
                    q.push({neigh, steps + 1, color});
                }
            }
        }

        return dist;
    }
};
