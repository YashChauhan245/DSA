https://leetcode.com/problems/pacific-atlantic-water-flow/?envType=daily-question&envId=2025-10-05

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));

        // DFS from Pacific (left and top borders)
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacificVisited, rows, cols);
            dfs(i, cols - 1, heights, atlanticVisited, rows, cols);
        }

        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, pacificVisited, rows, cols);
            dfs(rows - 1, j, heights, atlanticVisited, rows, cols);
        }
        //common from both the oceans
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
//dfs code
    void dfs(int x, int y, vector<vector<int>>& heights,
             vector<vector<bool>>& visited, int rows, int cols) {
        visited[x][y] = true;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if (isValid(newX, newY, rows, cols) && !visited[newX][newY] 
                && heights[newX][newY] >= heights[x][y]) {
                dfs(newX, newY, heights, visited, rows, cols);
            }
        }
    }
    bool isValid(int x, int y, int rows, int cols) {
        return (x >= 0 && y >= 0 && x < rows && y < cols);
    }
};
