https://leetcode.com/problems/making-a-large-island/description/


//DSU(BEST)
//T.C : O(m*n * alpha(m*n))
//S.C : O(m*n)

/*steps 
1)Treat each cell as a node (DSU)
Map (i, j) → i*n + j
2)Build islands
For every 1, union with adjacent 1s
Store size of each component
3)Find current max island
Check size of all 1 components
4)Try flipping each 0
Collect unique neighboring components
Sum their sizes + 1 (flipped cell)
5)Return maximum */

class Solution {
public:
    vector<int> parent, size;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void init(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // initialize DSU
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        // union by size
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int getSize(int x) {
        return size[find(x)]; // size of connected component
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalCells = n * n;
        init(totalCells);

        int maxArea = 0;

        // Step 1: connect all adjacent 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j; // map 2D -> 1D
                    for (auto &dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            Union(idx, ni * n + nj);
                        }
                    }
                }
            }
        }

        // Step 2: find max existing island
        for (int i = 0; i < totalCells; i++) {
            // map 1D index back to 2D: row = i/n, col = i%n
            if (grid[i / n][i % n] == 1) {
                maxArea = max(maxArea, getSize(i));
            }
        }

        // Step 3: try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> parents; // unique components

                    for (auto &dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            parents.insert(find(ni * n + nj));
                        }
                    }

                    int newSize = 1; // include flipped cell
                    for (auto p : parents) {
                        newSize += size[p];
                    }

                    maxArea = max(maxArea, newSize);
                }
            }
        }

        return maxArea;
    }
};



//Approach - 1 - Brute Force DFS (you can do BFS as well)
//T.C : O(n^4)
//S.C : O(n^2)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {  // Try converting each 0 to 1
                    grid[i][j] = 1;
                    
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int largest = 0;
                    
                    for(int x = 0; x < m; x++) {
                        for(int y = 0; y < n; y++) {
                            if(grid[x][y] == 1 && !visited[x][y]) {
                                largest = max(largest, DFS(grid, x, y, visited));
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, largest);
                    grid[i][j] = 0; // Backtrack
                }
            }
        }
        
        return (maxArea == 0) ? m * n : maxArea; // If the grid was full of 1s
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};

//Approach - 2 - Better Brute Force DFS (you can do BFS as well)
//T.C : O(n^4)
//S.C : O(n^2)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int size = DFS(grid, i, j, visited);
                    maxArea = max(maxArea, size);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {  // Try converting each 0 to 1
                    grid[i][j] = 1;
                    
                    visited = vector<vector<bool>>(n, vector<bool>(n, false));
                    int size = DFS(grid, i, j, visited);
                    
                    maxArea = max(maxArea, size);
                    grid[i][j] = 0; // Backtrack
                }
            }
        }
        
        return (maxArea == 0) ? m * n : maxArea; // If the grid was full of 1s
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};


//Approach - 3  - Optimal DFS (You can use BFS as well)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0},{0, 1},{0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, int& id) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = id;
        int count  = 1;
        
        for(vector<int>& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            count += DFS(grid, x, y, id);
        }
        
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int island_id = 2;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int size = DFS(grid, i, j, island_id);
                    maxArea = max(maxArea, size);
                    mp[island_id] = size;
                    island_id++;
                }
            }
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    for(vector<int>& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
                            st.insert(grid[x][y]);
                    }
                    
                    int sum = 1; //converting current 0 to 1
                    for(const int &s : st) {
                        sum += mp[s];
                    }
                    maxArea = max(maxArea, sum);
                }
            }
        }
        
        return maxArea;
    }
};
