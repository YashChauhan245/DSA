https://leetcode.com/problems/all-paths-from-source-to-target/description/?envType=study-plan-v2&envId=graph-theory


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;

        queue<vector<int>> q;//store paths instead of node
        q.push({0});

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            int node = path.back();

            // Reached target
            if (node == n - 1) {
                result.push_back(path);
                continue;
            }

            // Extend current path
            for (int neighbor : graph[node]) {
                vector<int> newPath = path;
                newPath.push_back(neighbor);

                q.push(newPath);
            }
        }

        return result;
    }
};
