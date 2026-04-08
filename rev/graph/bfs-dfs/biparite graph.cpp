https://leetcode.com/problems/is-graph-bipartite/description/

//Approach-1 (Graph coloring : DFS)
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color, int currColor) {
        color[node] = currColor;

        for (int &nbr : graph[node]) {
            // same color → not bipartite
            if (color[nbr] == color[node])
                return false;

            // not visited
            if (color[nbr] == -1) {
                if (!dfs(graph, nbr, color, 1 - currColor))
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = unvisited

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, color, 0)) // start with any color (0)
                    return false;
            }
        }
        return true;
    }
};


//Approach-2 (Graph coloring : BFS)

class Solution {
public:

    bool bfs(vector<vector<int>>& graph, int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0; // start with any color

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : graph[u]) {
                // same color → not bipartite
                if (color[v] == color[u])
                    return false;

                // not visited
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = unvisited

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};
