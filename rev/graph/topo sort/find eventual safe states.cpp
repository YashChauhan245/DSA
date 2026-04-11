https://leetcode.com/problems/find-eventual-safe-states/description/

/*
 1)reverse all the edges so that we can traverse the whole graph as if we traverse from indegree 0 we cant traverse whole graph
 2)again find new indegree 
 3)start topo from indegree 0 
*/


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);   //new graph  
        queue<int> que;
        vector<int> indegree(V, 0);
        int count = 0;

        //1.new graph and indegree count
        for(int u = 0; u < V; u++) {   //u->current node ,v->neigh node
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i]; //take the i-th neighbor of node u and store it in v
                adj[v].push_back(u); //new graph edges
                indegree[u]++;
            }
        }

        //2. Fill que, indegree with 0
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }

        //3. Simple BFS
        vector<bool> safe(V, false);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            safe[u] = true;

            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
