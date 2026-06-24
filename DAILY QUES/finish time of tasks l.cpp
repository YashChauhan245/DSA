https://leetcode.com/problems/finish-time-of-tasks-i/description/

/*
Implement DFS and it returns the finish time of the current node.
For a node:
    **If it has no children → return baseTime[node].
    **Otherwise:
        Collect finish times returned by all children.
        Find earliest = min(childFinish)
        Find latest = max(childFinish)
    **Compute -->ownDuration = (latest - earliest) + baseTime[node];
*/

class Solution {
public:
    long long dfs(int node, vector<vector<int>>& children, vector<int>& baseTime) {

        // Leaf node
        if (children[node].empty()) {
            return baseTime[node];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        // Compute finish times of all children
        for (int child : children[node]) {
            long long childFinish = dfs(child, children, baseTime);

            earliest = min(earliest, childFinish);
            latest = max(latest, childFinish);
        }

        long long ownDuration = (latest - earliest) + baseTime[node];

        return latest + ownDuration;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        // Build tree: parent -> children
        vector<vector<int>> children(n);

        for (int i = 0; i < edges.size(); i++) {
            int parent = edges[i][0];
            int child = edges[i][1];

            children[parent].push_back(child);
        }

        // Root is node 0
        return dfs(0, children, baseTime);
    }
};
