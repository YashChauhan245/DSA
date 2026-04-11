https://leetcode.com/problems/path-with-minimum-effort/description/


class Solution {
public:
    // {effort, {x, y}}
    typedef pair<int, pair<int, int>> P;
    
    // 4-directional movement (up, left, right, down)
    vector<vector<int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Check if cell is inside grid
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;
        
        while(!pq.empty()) {
            auto [diff, node] = pq.top();
            pq.pop();
            
            int x = node.first;
            int y = node.second;
            
            // If destination reached → return answer
            // Valid because min-heap ensures this is minimum possible effort
            if(x == m - 1 && y == n - 1)
                return diff;
            
            // Explore all 4 directions
            for(auto &dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if(isSafe(nx, ny)) {
                    
                    // Effort = max of current path effort and height difference of this edge
                    int newDiff = max(diff, abs(heights[x][y] - heights[nx][ny]));
                    if(result[nx][ny] > newDiff) {
                        result[nx][ny] = newDiff;
                        pq.push({newDiff, {nx, ny}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
