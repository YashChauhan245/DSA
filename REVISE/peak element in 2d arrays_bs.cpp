https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find max element in mid column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int midVal = mat[maxRow][mid];

            bool leftIsBigger = false;
            if (mid - 1 >= 0 && mat[maxRow][mid - 1] > midVal) {//mid-1 to check out of bound of row
                leftIsBigger = true;
            }

            bool rightIsBigger = false;
            if (mid + 1 < n && mat[maxRow][mid + 1] > midVal) {//mid+1 <n to check out of bound of coln
                rightIsBigger = true;
            }

            if (!leftIsBigger && !rightIsBigger) {
                return {maxRow, mid};
            } else if (rightIsBigger) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};
