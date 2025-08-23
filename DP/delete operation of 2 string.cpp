https://leetcode.com/problems/delete-operation-for-two-strings/description/

//recursive
// class Solution {
// public:
//     int solver(string &s1, string &s2, int i, int j) {
//         int n = s1.size(), m = s2.size();
//         if (i == n) return m - j;  // delete rest of s2
//         if (j == m) return n - i;  // delete rest of s1

//         if (s1[i] == s2[j]) {
//             return solver(s1, s2, i+1, j+1);
//         }

//         int iplus = 1 + solver(s1, s2, i+1, j);
//         int jplus = 1 + solver(s1, s2, i, j+1);

//         return min(iplus,jplus);
//     }
//     int minDistance(string word1, string word2) {
//         return solver(word1, word2, 0, 0);
//     }
// };



//top down 
// class Solution {
// public:
//     int solver(string &s1, string &s2, int i, int j,vector<vector<int>>&dp){
//         int n = s1.size(), m = s2.size();
//         if (i == n) return m - j;  // delete rest of s2
//         if (j == m) return n - i;  // delete rest of s1
        
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if (s1[i] == s2[j]) {
//             return dp[i][j]=solver(s1, s2, i+1, j+1,dp);
//         }
//         int iplus = 1 + solver(s1, s2, i+1, j,dp);
//         int jplus = 1 + solver(s1, s2, i, j+1,dp);
//         return dp[i][j]=min(iplus,jplus);
//     }

//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solver(word1, word2, 0, 0,dp);
//     }
// };



//bottom up 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;

        // bottom-up filling
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
