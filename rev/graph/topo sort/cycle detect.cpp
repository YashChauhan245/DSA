https://leetcode.com/problems/course-schedule/description/

class Solution {
public:

    bool topoCheck(vector<vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> q;
        int count = 0;

        // Step 1: Push all nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        // Step 2: BFS (Kahn's Algorithm)
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            // Traverse all neighbors
            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];

                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        // Step 3: Check if all nodes visited
        if(count == n) return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Indegree array
        vector<int> indegree(numCourses, 0);
        // Build graph
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // b → a
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoCheck(adj, numCourses, indegree);
    }
};
