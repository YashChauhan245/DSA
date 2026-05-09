https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int fr=0;
        int lr=n-1;
        int fc=0;
        int lc=m-1;

        while (fr < lr && fc < lc) {
            //STEP-1--->TRAVERSE OUTER RING
            vector<int> ring; //created fresh inside the while loop every time

            // top row
            for (int j = fc; j <= lc; j++) {
                ring.push_back(grid[fr][j]);
            }
            // right column
            for (int i = fr + 1; i <= lr; i++) {
                ring.push_back(grid[i][lc]);
            }
            // bottom row
            for (int j = lc - 1; j >= fc; j--) {
                ring.push_back(grid[lr][j]);
            }
            // left column
            for (int i = lr - 1; i > fr; i--) {
                ring.push_back(grid[i][fc]);
            }
   

            //STEP-2 -->ROTATE 
            int sz = ring.size();
            int rot = k % sz; //for rotations more then size

            // left rotate by rot
            reverse(ring.begin(), ring.end());
            reverse(ring.begin(), ring.begin() + (sz - rot));
            reverse(ring.begin() + (sz - rot), ring.end());
           

            //STEP-3-->PUT THE ROTATED ELEMENT BACK IN THE GRID 
            int idx = 0;
            // top row
            for (int j = fc; j <= lc; j++) {
                grid[fr][j] = ring[idx++];
            }
            // right column
            for (int i = fr + 1; i <= lr; i++) {
                grid[i][lc] = ring[idx++];
            }
            // bottom row
            for (int j = lc - 1; j >= fc; j--) {
                grid[lr][j] = ring[idx++];
            }
            // left column
            for (int i = lr - 1; i > fr; i--) {
                grid[i][fc] = ring[idx++];
            }
            
            //STEP-4 TRAVERSE INNER RINGS
            fr++;
            lr--;
            fc++;
            lc--;
        }
        return grid;
    }
};
