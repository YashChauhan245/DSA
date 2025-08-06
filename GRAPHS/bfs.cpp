https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
              //  adj = {{1, 2},    // adj[0]
              //        {0, 3},    // adj[1]
              //         {0},       // adj[2]
              //         {1} }:       // adj[3]

              // int node = 1;
              // Then:
              // adj[1] = {0, 3}
              // So:
              // adj[1][0] = 0
              // adj[1][1] = 3
              // no adj[1][2]  as its not present

                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};
