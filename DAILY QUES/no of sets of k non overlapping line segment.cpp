https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/?envType=daily-question&envId=2026-09-16




// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     int solver(int n, int k, int i, int cut) {

//         if (k == 0) {
//             return 1;
//         }

//         if (i >= n - 1) {
//             return 0;
//         }

//         if (cut == n) {
//             return solver(n, k, i + 1, i + 2);
//         }

//         int take = 0;

//         if (i < cut) {
//             take = solver(n, k - 1, cut, cut + 1)%MOD;
//         }

//         int skip = solver(n, k, i, cut + 1);

//         return (take + skip)%MOD;
//     }

//     int numberOfSets(int n, int k) {
//         return solver(n, k, 0, 1);
//     }
// };


//MLE 
// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     vector<vector<vector<int>>> dp;
//     int solver(int n, int k, int i, int cut) {

//         if (k == 0) {
//             return 1;
//         }

//         if (i >= n - 1) {
//             return 0;
//         }

//         if (cut >= n) {
//             return dp[k][i][cut] =solver(n, k, i + 1, i + 2);
//         }

//         if (dp[k][i][cut] != -1) {
//             return dp[k][i][cut];
//         }

//         int take = 0;

//         if (i < cut) {
//             take = solver(n, k - 1, cut, cut + 1);
//         }

//         int skip = solver(n, k, i, cut + 1);

//         return dp[k][i][cut] = (take + skip) % MOD;
//     }


//     int numberOfSets(int n, int k) {
//         dp.assign(k + 1,vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
//         return solver(n, k, 0, 1);
//     }
// };


//TLE
// class Solution {
// public:
//     int M = 1e9 + 7;
//     vector<vector<int>> t;

//     int solve(int n, int k, int i) {
//         if (k == 0)
//             return 1;

//         if (i >= n)
//             return 0;

//         if (t[k][i] != -1)
//             return t[k][i];

//         long long take = 0;

//         // start segment from ith point
//         for (int j = i + 1; j <= n - 1; j++) {
//             take = (take + solve(n, k - 1, j)) % M;
//         }

//         long long skip = solve(n, k, i + 1) % M;

//         return t[k][i] = (take + skip) % M;
//     }

//     int numberOfSets(int n, int k) {
//         t.assign(k + 1, vector<int>(n + 1, -1));
//         return solve(n, k, 0);
//     }
// };

//Approach-3 (Bottom Up + PrevRow Sum Precomputed)
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};
