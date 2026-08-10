https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2026-08-10


//RECURSION-->TLE

// class Solution {
// public:
//     int solver(vector<int>& piles, int i, int M, bool alice) {
//         if (i == piles.size())
//             return 0;

//         int n = piles.size();

//         if (alice) {
//             int best = 0;

//             for (int X = 1; X <= 2 * M && i + X <= n; X++) {
//                 int stones = 0;
//                 for (int j = i; j < i + X; j++)
//                     stones += piles[j];

//                 int newM = max(M, X);

//                 best = max(best,stones + solver(piles, i + X, newM, false));
//             }
//             return best;
//         }
//         else {
//             int best = INT_MAX;
//             for (int X = 1; X <= 2 * M && i + X <= n; X++) {
//                 int newM = max(M, X);
//                 best = min(best,solver(piles, i + X, newM, true));
//             }
//             return best;
//         }
//     }

//     int stoneGameII(vector<int>& piles) {
//         return solver(piles, 0, 1, true);
//     }
// };


//DP OPTIMAL 
class Solution {
public:

    int solver(vector<int>& piles, int i, int M, bool alice,vector<vector<vector<int>>>& dp) {
        if (i == piles.size())
            return 0;

        if (dp[i][M][alice] != -1)
            return dp[i][M][alice];

        int n = piles.size();

        if (alice) {
            int best = 0;

            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                int stones = 0;
                for (int j = i; j < i + X; j++)
                    stones += piles[j];

                int newM = max(M, X);

                best = max(best,stones + solver(piles, i + X, newM, false, dp));
            }
            return dp[i][M][alice] = best;
        }


        else {
            int best = INT_MAX;

            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                int newM = max(M, X);
                best = min(best,solver(piles, i + X, newM, true, dp)
                );
            }

            return dp[i][M][alice] = best;
        }
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(n + 1,vector<int>(2, -1)));
        return solver(piles, 0, 1, true, dp);
    }
};
