https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-08-19


class Solution {
public:
    vector<vector<pair<long long, long long>>> dp;
    vector<vector<bool>> vis;

    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Already calculated
        if (vis[i][j]) {
            return dp[i][j];
        }

        // Base case
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = {
                grid[i][j],
                grid[i][j]
            };
        }

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        // Right
        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);

            mx = max({
                mx,
                rightMax * grid[i][j],
                rightMin * grid[i][j]
            });

            mn = min({
                mn,
                rightMax * grid[i][j],
                rightMin * grid[i][j]
            });
        }

        // Down
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, grid);

            mx = max({
                mx,
                downMax * grid[i][j],
                downMin * grid[i][j]
            });

            mn = min({
                mn,
                downMax * grid[i][j],
                downMin * grid[i][j]
            });
        }

        vis[i][j] = true;
        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.resize(m, vector<pair<long long, long long>>(n));
        vis.resize(m, vector<bool>(n, false));

        auto [mx, mn] = solve(0, 0, grid);

        if (mx < 0)
            return -1;

        return mx % 1000000007;
    }
};
