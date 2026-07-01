https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01


class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        //new dist grid
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        

        //building dist grid with multi-source bfs
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (dist[nr][nc] != INT_MAX)  //already visisted
                    continue;

                dist[nr][nc] = dist[r][c] + 1; //new dist
                q.push({nr, nc});
            }
        }
        

        //Dijkstra to find one whose safeness factor is Max

        priority_queue<vector<int>> pq; //safe,row,coln
        vector<vector<int>> best(n, vector<int>(n, -1));  //he best safeness so far to reach (i,j)

        pq.push({dist[0][0], 0, 0}); //safe,row,coln
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == n - 1) //reached distination
                return safe;

            if (safe < best[r][c])
                continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int newSafe = min(safe, dist[nr][nc]);  //min from current path

                if (newSafe > best[nr][nc]) {  //max safeness factor
                    best[nr][nc] = newSafe;
                    pq.push({newSafe, nr, nc});
                }
            }
        }
        return 0;
    }
};
