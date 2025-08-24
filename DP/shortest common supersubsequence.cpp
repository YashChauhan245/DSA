https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

APPROACH -1) USING TAKE AND SKIP 
// //recursive
// class Solution {
//   public:
//     int solve(string &s1, string &s2, int i, int j) {
//         int n = s1.size();
//         int m = s2.size();

//         // Base cases
//         if (i == n) return m - j;  // remaining s2
//         if (j == m) return n - i;  // remaining s1

//         if (s1[i] == s2[j]) {
//             return 1 + solve(s1, s2, i + 1, j + 1);
//         } else {
//             int left  = 1 + solve(s1, s2, i + 1, j);
//             int right = 1 + solve(s1, s2, i, j + 1);
//             return min(left, right);
//         }
//     }

//     int shortestCommonSupersequence(string &s1, string &s2) {
//         return solve(s1, s2, 0, 0);
//     }
// };

//top down 
// class Solution {
//   public:
//     int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
//         int n = s1.size(), m = s2.size();

//         // base cases
//         if (i == n) return m - j;  // take rest of s2
//         if (j == m) return n - i;  // take rest of s1

//         if (dp[i][j] != -1) return dp[i][j];


//         if (s1[i] == s2[j]) {
//             return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
//         } 
//         else {
//             int left  = 1 + solve(s1, s2, i + 1, j, dp);  
//             int right = 1 + solve(s1, s2, i, j + 1, dp);  
//             return dp[i][j] = min(left, right);
//         }
//     }

//     int shortestCommonSupersequence(string &s1, string &s2) {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return solve(s1, s2, 0, 0, dp);
//     }
// };



//bottom up

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = length of shortest common supersequence of s1[i..], s2[j..]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: when one string is empty
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;

        // Fill the table in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};



APPROACH-2)USING LONGEST COMMON SUBSEQUENCE

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the table in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }

    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        int LCS = lcs(s1, s2);
        return n + m - LCS;
    }
};


