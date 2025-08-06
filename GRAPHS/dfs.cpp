https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void helper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        if (visited[node]) return;

        visited[node] = true;
        result.push_back(node);
           //  adj[0] → {1, 2}
          // adj[0][1] → 2
          // So neighbor = 2
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            helper(neighbor, adj, visited, result);
        }
        // for (int neighbor : adj[node]) {
        //     helper(neighbor, adj, visited, result);
        // }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();  // Total number of nodes
        vector<bool> visited(V, false);
        vector<int> result;

        helper(0, adj, visited, result);  // start DFS from node 0

        return result;
    }
};
