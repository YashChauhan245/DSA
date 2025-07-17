https://leetcode.com/problems/maximal-rectangle/description/


APPROACH-1) USING PREFIX SUM STORING IN MATRIX .... AND SUMMING COLUMNWISE
class Solution {
public:
    vector<int> findNSE(vector<int>& heights) {
        stack<int> st;
        vector<int> nse(heights.size());
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>& heights) {
        stack<int> st;
        vector<int> pse(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        // Build prefix heights column-wise
        for (int j = 0; j < m; ++j) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                prefix[i][j] = sum;
            }
        }

        // Apply LC 84 row-wise using the built prefix heights
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, largestRectangleArea(prefix[i]));
        }

        return maxArea;
    }
};



APPROACH-2)SPACE OPTIMISED ...PREFIX SUM ROWWISE IN 1D ARRAY FOR EACH ROW 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> nse(n), pse(n);

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Compute max area
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);  // Dynamic vertical prefix sum (histogram)

        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Update prefix sum for each column
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Apply LC84 logic on updated histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
