https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/?envType=daily-question&envId=2026-07-02


//using modified bfs
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> bestHealth(m, vector<int>(n, -1));

        queue<vector<int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        q.push({0, 0, startHealth});
        bestHealth[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int h = cur[2];

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = h - grid[nr][nc];

                if (newHealth <= 0)
                    continue;

                // Already reached this cell with equal or more health.
                if (bestHealth[nr][nc] >= newHealth)
                    continue;

                bestHealth[nr][nc] = newHealth;
                q.push({nr, nc, newHealth});
            }
        }

        return false;
    }
};


// using 0-1 bfs
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0]; //source {0, 0}
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {

                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0) 
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};
