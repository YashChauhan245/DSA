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

TOO MUCH TRICKY...SO USE TOPO SORT
as if topo sort fails i.e there is a cycle as topo sort only works then there is no cycle

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<int> adj[N];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        // Step 2: Compute indegree of each vertex
        vector<int> indegree(N, 0);
        for (int u = 0; u < N; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        
        // Step 3: Push vertices with indegree 0 into queue
        queue<int> que;
        int count = 0; // number of processed nodes/visited nodes
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        
        // Step 4: BFS (Kahn's Algorithm)
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        
        //If count != N → that means some nodes never got processed because their indegree never became 0
        // which happens only when there’s a cycle.
        // return count != N;
         if(count==N){
          return false;
         }
         return false;
};

  
