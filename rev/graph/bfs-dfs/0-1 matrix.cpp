https://leetcode.com/problems/01-matrix/description/


class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
    
        queue<vector<int>> que;

        // Distance matrix initialized with -1
        vector<vector<int>> dist(m, vector<int>(n, -1));
        //Push all 0 cells into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        } 
        while(!que.empty()) {
            vector<int> p = que.front();
            que.pop();

            int row = p[0];
            int col = p[1];

            for(auto &dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if(dist[newRow][newCol] == -1) {
                        dist[newRow][newCol] = 1 + dist[row][col];
                        que.push({newRow, newCol});
                    }
                }
            }
        }
        return dist;
    }
};
