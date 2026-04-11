https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // undirected
        }

        // Step 2: Distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // Step 3: BFS
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &neigh : adj[node]) {
                if (dist[node] + 1 < dist[neigh]) {
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }

        // Step 4: Replace unreachable nodes with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
