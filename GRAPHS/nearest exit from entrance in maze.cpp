https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=graph-theory



class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();       
        int m = maze[0].size();   

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});

        // Mark entrance visited
        maze[entrance[0]][entrance[1]] = '+';

        int distance = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= m) {
                        continue;
                    }

                    if (maze[nr][nc] == '+') {
                        continue;
                    }

                    maze[nr][nc] = '+';//mark visited

                    if (nr == 0 || nr == n - 1 ||
                        nc == 0 || nc == m - 1) {
                        return distance + 1;
                    }

                    q.push({nr, nc});
                }
            }

        distance++;
        
        }
        return -1;
    }
};
