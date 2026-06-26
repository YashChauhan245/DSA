https://leetcode.com/problems/valid-sudoku/description/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                char num = board[i][j];

                int box = (i / 3) * 3 + (j / 3);
                /*
                i/3 gives row block: 
                    Rows 0,1,2  -> 0
                    Rows 3,4,5  -> 1
                    Rows 6,7,8  -> 2
                j/3 gives col block:
                    Columns 0,1,2 -> 0
                    Columns 3,4,5 -> 1
                    Columns 6,7,8 -> 2
                   

                    0 0 0 | 1 1 1 | 2 2 2
                    0 0 0 | 1 1 1 | 2 2 2
                    0 0 0 | 1 1 1 | 2 2 2
                    ---------------------
                    3 3 3 | 4 4 4 | 5 5 5
                    3 3 3 | 4 4 4 | 5 5 5
                    3 3 3 | 4 4 4 | 5 5 5
                    ---------------------
                    6 6 6 | 7 7 7 | 8 8 8
                    6 6 6 | 7 7 7 | 8 8 8
                    6 6 6 | 7 7 7 | 8 8 8
                */

                // Check if number already exists
                if (rows[i].count(num) ||
                    cols[j].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Store the number
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};
