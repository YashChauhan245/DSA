https://leetcode.com/problems/largest-local-values-in-a-matrix-ii/

//MY APPROACH-->TLE o(n4)
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // store coordinates of each value
        vector<pair<int,int>> pos[201];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[matrix[i][j]].push_back({i, j});
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = matrix[i][j];
                // skip zero cells
                if (x == 0)
                    continue;
                bool greaterFound = false;
                // check only greater values
                for (int val = x + 1; val <= 200 && !greaterFound; val++) {
                    for (auto &[r, c] : pos[val]) {
                        int dr = abs(r - i);
                        int dc = abs(c - j);
                        // inside allowed range
                        if (dr <= x && dc <= x) {
                            // ignore corners
                            if (dr == x && dc == x)
                                continue;
                            greaterFound = true;
                            break;
                        }
                    }
                }
                // no greater value found
                if (!greaterFound)
                    count++;
            }
        }
        return count;
    }
};


//Optimal --->range sum query/segment tree
