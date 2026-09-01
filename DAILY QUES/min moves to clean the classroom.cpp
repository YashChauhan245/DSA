https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/?envType=daily-question&envId=2026-09-01


/* 
Start
 ↓
Find S and number all L as 0,1,2...
 ↓
BFS state = (row, col, energy, mask)
 ↓
For every 4-direction move:
 ↓
Out of bounds / X? → Skip
 ↓
energy - 1
 ↓
L? → set its bit in mask
R? → reset energy to max
 ↓
Already reached (r,c,mask) with >= energy?
 → Yes: Skip
 → No: Update best and push
 ↓
mask == allMask?
 → Yes: return moves
 → No: continue BFS
 ↓
Queue empty → return -1
*/

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        // Give every L a number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt;
                    cnt++;
                }
            }
        }

        int all = (1 << cnt) - 1;

        // best[r][c][mask] = maximum energy seen
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        // {row, col, energy, mask}
        queue<vector<int>> q;

        q.push({sr, sc, energy, 0});
        best[sr][sc][0] = energy;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto cur = q.front();
                q.pop();

                int r = cur[0];
                int c = cur[1];
                int e = cur[2];
                int mask = cur[3];

                if (mask == all)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Invalid cell
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L')
                        nmask |= (1 << id[nr][nc]);

                    // Reset
                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    // We already reached this state
                    // with equal or more energy
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};
