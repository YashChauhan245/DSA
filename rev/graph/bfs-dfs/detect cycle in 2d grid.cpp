https://leetcode.com/problems/detect-cycles-in-2d-grid/

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<bool>> visited(m, vector<bool>(n, false));     
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(bfs(grid, visited, i, j, dirs))//starting row,starting coln
                        return true;
                }
            }
        }
        return false;
    }
    
    bool bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,int sr, int sc, vector<pair<int,int>>& dirs) {
        int m = grid.size(), n = grid[0].size();
        char ch = grid[sr][sc];
        
        // queue stores: {current_row, current_col, parent_row, parent_col}
        queue<tuple<int,int,int,int>> q;
        
        q.push({sr, sc, -1, -1});
        visited[sr][sc] = true;
        
        while(!q.empty()) {
            auto [r, c, pr, pc] = q.front();
            q.pop();
            
            // explore all 4 directions
            for(auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                
                if(grid[nr][nc] != ch)
                    continue;
                
                // case 1: neighbor not visited → continue BFS
                if(!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, r, c}); // mark current as parent
                }
                // case 2: visited AND not parent → cycle found
                else if(nr != pr || nc != pc) {
                    return true;
                }
            }
        }
        return false;
    }
};
