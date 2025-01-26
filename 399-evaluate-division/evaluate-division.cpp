class Solution {
public:
    bool dfs(const string &start, const string &end, unordered_map<string, vector<pair<string, double>>> &graph, 
             unordered_set<string> &visited, double &result, double currentProduct) {
        if (visited.count(start)) return false;
        visited.insert(start);

        if (start == end) {
            result = currentProduct;
            return true;
        }

        for (const auto &neighbor : graph[start]) {
            if (dfs(neighbor.first, end, graph, visited, result, currentProduct * neighbor.second)) {
                return true;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            const string &var1 = equations[i][0];
            const string &var2 = equations[i][1];
            double value = values[i];

            graph[var1].emplace_back(var2, value);
            graph[var2].emplace_back(var1, 1.0 / value);
        }

        vector<double> results;

        // Process each query
        for (const auto &query : queries) {
            const string &var1 = query[0];
            const string &var2 = query[1];

            if (graph.find(var1) == graph.end() || graph.find(var2) == graph.end()) {
                results.push_back(-1.0);  // Variable not in graph
                continue;
            }

            if (var1 == var2) {
                results.push_back(1.0);  // Same variable
                continue;
            }

            unordered_set<string> visited;
            double result = -1.0;

            if (dfs(var1, var2, graph, visited, result, 1.0)) {
                results.push_back(result);
            } else {
                results.push_back(-1.0);  // No path found
            }
        }

        return results;
    }
};
