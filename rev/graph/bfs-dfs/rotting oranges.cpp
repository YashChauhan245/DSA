https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();       
        int n = grid[0].size();     

        queue<vector<int>> que;    
        int freshCount = 0;        

        // Step 1: Traverse grid
        // Push all rotten oranges into queue
        // Count fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    que.push({i, j}); 
                }
                else if(grid[i][j] == 1) {
                    freshCount++;     
                }
            }
        }

        // If no fresh oranges → no time needed
        if(freshCount == 0)
            return 0;

        int time = -1; 

        // Step 2: Multi-source BFS
        // Process level by level (each level = 1 minute)
        while(!que.empty()) {
            int size = que.size(); 
            while(size--) {
                vector<int> curr = que.front();
                que.pop();

                int i = curr[0];
                int j = curr[1];

                // Check valid neighbour in all 4 directions 
                for(int k = 0; k < directions.size(); k++) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];

                    // Check:
                    // 1. within bounds
                    // 2. is fresh orange
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;     // make it rotten
                        que.push({ni, nj});   // push into queue
                        freshCount--;         // decrease fresh count
                    }
                }
            }

            time++;  // (1 minute passed)
        }
        return (freshCount == 0) ? time : -1;
    }
};


//Directions 
// UP
// if(i-1 >= 0 && grid[i-1][j] == 1) {
//     grid[i-1][j] = 2;
//     que.push({i-1, j});
//     freshCount--;
// }

// // DOWN
// if(i+1 < m && grid[i+1][j] == 1) {
//     grid[i+1][j] = 2;
//     que.push({i+1, j});
//     freshCount--;
// }

// // LEFT
// if(j-1 >= 0 && grid[i][j-1] == 1) {
//     grid[i][j-1] = 2;
//     que.push({i, j-1});
//     freshCount--;
// }

// // RIGHT
// if(j+1 < n && grid[i][j+1] == 1) {
//     grid[i][j+1] = 2;
//     que.push({i, j+1});
//     freshCount--;
// }
