https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

***DFS***

class Solution {
  public:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        for (int v : adj[u]) {
          //IF NOT VISITED THEN CHECK FURTHER AND IF FIND CYCCLE RETURN TRUE;
            if (!visited[v] && dfs(v, adj, visited, inRecursion))
                return true;
              //IF VISITED ...SO NOW CHECK RECUSIVE STACK (IS IT TRUE IF YES) THEN RETURN TRUE 
            else if (inRecursion[v])
                return true;
        }
        
        inRecursion[u] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // Step 2: Arrays to track visited nodes and recursion stack
        vector<bool> visited(V, false), inRecursion(V, false);
        
        // Step 3: Run DFS from every unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfs(i, adj, visited, inRecursion))
                return true;
        }
        
        return false;
    }
};



****BFS***

TOO MUCH TRICKY TO USE TOPO SORT

  
