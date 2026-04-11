https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  private:
    void topoSort(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            if (!vis[it.first]) {
                topoSort(it.first, adj, vis, st);
            }
        }

        st.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 3: Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // source is 0 (as per GFG problem)

        // Step 4: Relax edges in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto &it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Replace unreachable with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
