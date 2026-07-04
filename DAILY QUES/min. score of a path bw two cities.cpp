https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04


class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n + 1);

        // Build adjacency list
        for (auto &road : roads) {
            int a = road[0];
            int b = road[1];
            int dist = road[2];

            graph[a].push_back({b, dist});
            graph[b].push_back({a, dist});
        }

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();


            for (int i = 0; i < graph[node].size(); i++) {
                // i = 0
                //graph[1][0] = {2,9}  -->(neighbor city, road distance)-->city 1 to 2 distance 10
                int nei = graph[node][i].first;   //nei = graph[1][0].first  // 2   
                int dist = graph[node][i].second; //dist = graph[1][0].second // 9

                ans = min(ans, dist);

                if (visited[nei] == false) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};
