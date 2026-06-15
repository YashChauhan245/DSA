https://leetcode.com/problems/magic-squares-in-grid/description/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {

                vector<int> freq(10, 0);
                bool valid = true;

                // distinct numbers 1..9 in 3*3 grid 
                for (int r = i; r < i + 3 && valid; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int x = grid[r][c];

                        if (x < 1 || x > 9 || freq[x]) {
                            valid = false;
                            break;
                        }

                        freq[x] = 1;
                    }
                }

                if (!valid) continue;

                int target =grid[i][j] + grid[i][j + 1] +grid[i][j + 2];

                // rows
                for (int r = i + 1; r < i + 3; r++) {
                    int rowSum =grid[r][j] +grid[r][j + 1] +grid[r][j + 2];

                    if (rowSum != target) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) continue;

                // columns
                for (int c = j; c < j + 3; c++) {
                    int colSum =grid[i][c] +grid[i + 1][c] + grid[i + 2][c];

                    if (colSum != target) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) continue;

                int diag =grid[i][j] +grid[i + 1][j + 1] +grid[i + 2][j + 2];

                int antiDiag =grid[i][j + 2] +grid[i + 1][j + 1] + grid[i + 2][j];

                if (diag == target && antiDiag == target)
                    count++;
            }
        }

        return count;
    }
};
