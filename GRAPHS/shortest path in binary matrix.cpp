https://leetcode.com/problems/shortest-path-in-binary-matrix/description/


//Approach-1 (Using BFS - Works because all edges are of weight = 1)
class Solution {
public:
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;
        
        queue<pair<int, int>> que;
        que.push({0, 0});
        grid[0][0] = 1;
        
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        
        int steps = 1;
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {

                auto curr = que.front();
                que.pop();
                int x = curr.first;
                int y = curr.second;

                if(x == m-1 && y == n-1)
                    return steps;

                for(auto dir:directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_) && grid[x_][y_] == 0) {
                        que.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};


//Approach-2 (Using Dijkstra's Algorithm) - Using Priority_queue (min-heap)
class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m-1][n-1] != 0) 
            return -1;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({1, {0,0}});   // path length starts from 1 or we can have to add +1 in final lenght
        dist[0][0] = 1;
  
        while (!pq.empty()) {
            int d  = pq.top().first;
            auto [x, y] = pq.top().second;
            pq.pop();
            
            if (x == m-1 && y == n-1) return d; // reached target
            
            if (d > dist[x][y]) continue; // skip outdated

            for (auto &dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (isSafe(nx, ny) && grid[nx][ny] == 0 && d + 1 < dist[nx][ny]) {
                    dist[nx][ny] = d + 1;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        
        return -1;
    }
};


//Approach-3 (Using Dijkstra's Algorithm) - Using queue (min-heap)
//This works because every weight is 1 and it will be similar to min-heap only
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<P> pq;
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;
  
        while(!pq.empty()) {
            int d  = pq.front().first;
	    pair<int, int> node = pq.front().second;
	    pq.pop();

            int x = node.first;
            int y = node.second;
            
	    for(auto dir:directions) {
		int x_   = x + dir[0];
		int y_   = y + dir[1];
		int dist = 1;

		if(isSafe(x_, y_) && grid[x_][y_] == 0 && d+dist < result[x_][y_]) {
		    pq.push({d+dist, {x_, y_}});
		    grid[x_][y_] = 1;
		    result[x_][y_] = d + dist;
		}
            }
        }
        
        if(result[m-1][n-1] == INT_MAX)
            return -1;
        
        return result[m-1][n-1]+1;
        
    }
};
