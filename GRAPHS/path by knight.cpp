https://www.geeksforgeeks.org/problems/steps-by-knight5927/1?page=2&category=Graph%2CDFS%2CBFS&sortBy=submissions

class Solution {
public:
    vector<vector<int>> coordinates = {
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
    };

    int helper(int src_x, int src_y, int target_x, int target_y, int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({src_x, src_y});
        visited[src_x][src_y] = 1;

        int steps = 0;

        while (!q.empty()) {
            int qSize = q.size();
          //iterating all child of curr level in one cycle 
            while (qSize--) {
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first, y = p.second;
              //checking --target tk aa gye ya nhi 
                if (x == target_x && y == target_y) {
                    return steps;
                }
               //iterating bfs of childs
                for (int k = 0; k < coordinates.size(); k++) {
                    int new_x = x + coordinates[k][0];
                    int new_y = y + coordinates[k][1];
                //edge cases 
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n && visited[new_x][new_y] == 0) {
                        visited[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }
            }
            steps++;
        }
     //if target not found (rare case)
        return -2;
    }

    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int n) {
        //changing coordinates 
        int src_x = n-KnightPos[1];
        int src_y = KnightPos[0] - 1;
        int target_x = n-TargetPos[1];
        int target_y = TargetPos[0]-1;

        return helper(src_x, src_y, target_x, target_y, n);
    }
};
