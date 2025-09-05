https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

//recursive
// class Solution {
// public:
//     int m, n;

//     int solve(int i, int j, vector<vector<int>>& grid) {
//         // Out of bounds
//         if (i >= m || j >= n) 
//             return 0;

//         // If current cell is 0, no square possible
//         if (grid[i][j] == 0)
//             return 0;

//         // Recursive calls
//         int right = solve(i, j + 1, grid);      // move right
//         int diagonal = solve(i + 1, j + 1, grid); // move diagonal
//         int below = solve(i + 1, j, grid);     // move down

//         // size of largest square starting at (i,j)
//         return 1 + min({right, diagonal, below});
//     }

//     int countSquares(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int result = 0;

//         // Try starting from every cell
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 result += solve(i, j, grid);
//             }
//         }
//         return result;
//     }
// };




//top down 

// class Solution {
// public:
//     int m, n;

//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         // Out of bounds
//         if (i >= m || j >= n) 
//             return 0;

//         // If current cell is 0, no square possible
//         if (grid[i][j] == 0)
//             return 0;

//         // If already computed, return cached result
//         if (dp[i][j] != -1) 
//             return dp[i][j];

//         // Recursive calls
//         int right = solve(i, j + 1, grid, dp);      // move right
//         int diagonal = solve(i + 1, j + 1, grid, dp); // move diagonal
//         int below = solve(i + 1, j, grid, dp);     // move down

//         return dp[i][j] = 1 + min({right, diagonal, below});
//     }

//     int countSquares(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int result = 0;

//         // Memo table initialized with -1
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 result += solve(i, j, grid, dp);
//             }
//         }
//         return result;
//     }
// };






//bottom up 

class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int result = 0;

        // fill bottom-up (reverse order)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i == m - 1 || j == n - 1) {
                        // last row or last col → only itself
                        dp[i][j] = 1;
                    } else {
                        int right = dp[i][j + 1];
                        int diagonal = dp[i + 1][j + 1];
                        int below = dp[i + 1][j];
                        dp[i][j] = 1 + min({right, diagonal, below});
                    }
                }
                result += dp[i][j];
            }
        }
        return result;
    }

    int countSquares(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        return solve(grid, dp);
    }
};
