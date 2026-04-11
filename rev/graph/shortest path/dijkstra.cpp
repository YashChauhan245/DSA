https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Create adjacency list
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove if directed graph
        }
        
        // Step 2: Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        // Step 3: Min heap → {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        // Step 4: Dijkstra
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip outdated entries
            if(d > dist[u]) continue;
            
            for(auto &nbr : adj[u]) {
                int v = nbr.first;
                int wt = nbr.second;
                
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};
