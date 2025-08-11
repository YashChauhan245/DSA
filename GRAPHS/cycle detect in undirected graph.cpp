https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

****DFS****
  
class Solution {
  public:
    bool bfsCycleCheck(int src, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int, int>> q; // {node, parent}
        visited[src] = true;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, node});
                }
                else if (neigh != parent) {
                    // Found visited node that's not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        // Step 2: BFS for each component
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCycleCheck(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
