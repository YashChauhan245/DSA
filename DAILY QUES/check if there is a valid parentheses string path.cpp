https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/?envType=daily-question&envId=2026-09-29



//RECURSION 

// class Solution {
// public:
//     bool solve(int i, int j, vector<vector<char>>& grid, int balance) {
//         int m = grid.size();
//         int n = grid[0].size();

//         // update balance
//         if (grid[i][j] == '(')
//             balance++;
//         else
//             balance--;

//         // invalid prefix
//         if (balance < 0)
//             return false;

//         // reached bottom-right
//         if (i == m - 1 && j == n - 1) {
//             if (balance == 0)
//                 return true;
//             else
//                 return false;
//         }

//         bool down = false;
//         bool right = false;

//         // move down
//         if (i + 1 < m)
//             down = solve(i + 1, j, grid, balance);

//         // move right
//         if (j + 1 < n)
//             right = solve(i, j + 1, grid, balance);

//         return down || right;
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         return solve(0, 0, grid, 0);
//     }
// };




//TOP DOWN 
class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& grid,int balance, vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;


        if (balance < 0)
            return false;


        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }


        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = false;
        bool right = false;


        if (i + 1 < m)
            down = solve(i + 1, j, grid, balance, dp);


        if (j + 1 < n)
            right = solve(i, j + 1, grid, balance, dp);

        return dp[i][j][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m + n + 1, -1)));

        return solve(0, 0, grid, 0, dp);
    }
};
