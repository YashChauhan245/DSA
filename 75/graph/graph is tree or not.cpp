https://www.geeksforgeeks.org/problems/is-it-a-tree/1

class Solution {
  public:
  
    // DFS function to detect cycle in undirected graph
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis) {
        vis[node] = true;  // mark current node as visited
        
        for (auto neigh : adj[node]) {
            
            // If neighbor is not visited → go deeper
            if (!vis[neigh]) {
                if (dfs(neigh, node, adj, vis))
                    return true;  // cycle found in recursion
            }
            
            // If neighbor is visited and not parent → cycle exists
            else if (neigh != parent) {
                return true;
            }
        }
        
        return false; // no cycle found
    }
  
    int isTree(int n, int m, vector<vector<int>> &edges) {
        
        // 🌟 Condition 1: Tree must have exactly n-1 edges
        // If not, it can't be a tree
        if (m != n - 1) return 0;
        
        // Step 1: Build adjacency list from edge list
        vector<int> adj[n];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // because undirected graph
        }
        
        // Visited array to track visited nodes
        vector<bool> vis(n, false);
        
        // Step 2: Check for cycle using DFS
        // Start DFS from node 0 (assuming nodes are 0-based)
        if (dfs(0, -1, adj, vis)) return 0;
        
        // Step 3: Check if graph is connected
        // All nodes must be visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return 0; // disconnected graph
        }
        
        // If no cycle + fully connected → it's a tree
        return 1;
    }
};
