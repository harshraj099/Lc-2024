class Solution {
public:
    int dfs(int node,vector<bool>&visited,vector<int>& leftChild, vector<int>& rightChild){
        if (node == -1) return true;
        if (visited[node]) return false; // cycle
        visited[node] = true;
        return dfs(leftChild[node],visited,leftChild,rightChild) && dfs(rightChild[node],visited,leftChild,rightChild);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
    // Step 1: count indegrees
    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            if (++indegree[leftChild[i]] > 1) return false;
        }
        if (rightChild[i] != -1) {
            if (++indegree[rightChild[i]] > 1) return false;
        }
    }

    // Step 2: find root (only one with indegree 0)
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            if (root != -1) return false; // multiple roots
            root = i;
        }
    }

    if (root == -1) return false; // no root

    // Step 3: DFS to check connectivity & cycles
    vector<bool> visited(n, false);
    if (!dfs(root,visited,leftChild,rightChild)) return false;

    // Final check: all nodes visited
    for (bool v : visited)
        if (!v) return false;

    return true;
    }
};