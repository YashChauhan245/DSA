https://leetcode.com/problems/flood-fill/description/

****DFS****

class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Boundary check
        if (x < 0 || y < 0 || x >= n || y >= m) return;

        // Stop if the cell is not the old color
        if (image[x][y] != oldColor) return;

        // Fill the cell
        image[x][y] = newColor;

        // Explore neighbors (4 directions)
        dfs(image, x + 1, y, oldColor, newColor);
        dfs(image, x - 1, y, oldColor, newColor);
        dfs(image, x, y + 1, oldColor, newColor);
        dfs(image, x, y - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color) { // Avoid infinite loop
            dfs(image, sr, sc, oldColor, color);
        }
        return image;
    }
};





***BFS***

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == oldColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
