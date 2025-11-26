https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

//RECURSIVE 
class Solution {
public:
    int M = 1e9 + 7;

    int solve(int r, int c, int rem, vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (r >= m || c >= n)
            return 0;

        // Destination
        if (r == m - 1 && c == n - 1)
            return ((rem + grid[r][c]) % k == 0);

        int newRem = (rem + grid[r][c]) % k;

        // Move down
        int down = solve(r + 1, c, newRem, grid, k);

        // Move right
        int right = solve(r, c + 1, newRem, grid, k);

        return (down + right) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        return solve(0, 0, 0, grid, k);
    }
};


//TOP-DOWN 
class Solution {
public:
    int M = 1e9 + 7;

    int solver(int row, int col, int rem, vector<vector<int>>& grid, int k,
               vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (row >= m || col >= n) {
            return 0;
        }

        // Destination cell
        if (row == m - 1 && col == n - 1) {
            return ((rem + grid[row][col]) % k == 0);
        }

        // Memo check
        if (dp[row][col][rem] != -1) {
            return dp[row][col][rem];
        }

        int newRem = (rem + grid[row][col]) % k;

        // Move down
        int down = solver(row + 1, col, newRem, grid, k, dp);

        // Move right
        int right = solver(row, col + 1, newRem, grid, k, dp);

        return dp[row][col][rem] = (down + right) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1))
        );

        return solver(0, 0, 0, grid, k, dp);
    }
};


//BOTTOM-UP
class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[r][c][rem] = ways to reach (m-1, n-1) starting at (r,c) with remainder rem
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0))
        );

        // Base case: destination cell
        for (int rem = 0; rem < k; rem++) {
            dp[m - 1][n - 1][rem] = ((rem + grid[m - 1][n - 1]) % k == 0);
        }

        // Fill table from bottom-right → top-left
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {

                if (r == m - 1 && c == n - 1) continue; // already initialized

                for (int rem = 0; rem < k; rem++) {

                    int newRem = (rem + grid[r][c]) % k;

                    long long ways = 0;

                    if (r + 1 < m) ways += dp[r + 1][c][newRem];
                    if (c + 1 < n) ways += dp[r][c + 1][newRem];

                    dp[r][c][rem] = ways % M;
                }
            }
        }

        // Start at (0,0) with remainder = 0
        return dp[0][0][0];
    }
};
