https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Swap element at (i, j) with (j, i) to transpose
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            // Reverse the current row to complete clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        } 
    }
};
