https://www.geeksforgeeks.org/problems/topological-sort/1

**DFS**
class Solution {
  public:
    void dfs(int u, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        //baccho ko push kro dfs krke ke liye 
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v, adj, visited, st);
        }
       //stack me mujhe dalo  
        st.push(u);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        // Step 2: DFS-based topo sort
        vector<bool> visited(V, false);
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }
        
        // Step 3: Get result from stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};




***BFS***

