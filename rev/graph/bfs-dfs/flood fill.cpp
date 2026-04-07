https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        // avoid infinite loop
        if(oldColor == newColor)
            return image;

        // Direction array (up, down, left, right)
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>> q;

        // Start BFS from given pixel
        q.push({sr, sc});
        image[sr][sc] = newColor;

        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int i = curr[0];
            int j = curr[1];

            // Check all 4 directions
            for(int k = 0; k < directions.size(); k++) {
                int ni = i + directions[k][0];
                int nj = j + directions[k][1];

                // Check:
                // 1. inside grid
                // 2. same original color
                if(ni >= 0 && nj >= 0 && ni < m && nj < n && image[ni][nj] == oldColor) {
                    image[ni][nj] = newColor;   // change color
                    q.push({ni, nj});           // add to queue
                }
            }
        }

        return image;
    }
};
