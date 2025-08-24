https://leetcode.com/problems/shortest-common-supersequence/description/

//recursive
// class Solution {
// public:
//     string solver(string &s1, string &s2, int i, int j) {
//         int n = s1.size(), m = s2.size();
        
//         // Base cases
//         if (i == n) return s2.substr(j);  // take remaining s2
//         if (j == m) return s1.substr(i);  // take remaining s1

//         if (s1[i] == s2[j]) {
//             return s1[i] + solver(s1, s2, i + 1, j + 1);
//         } 
//         else {
//             string takeS1 = s1[i] + solver(s1, s2, i + 1, j);
//             string takeS2 = s2[j] + solver(s1, s2, i, j + 1);
            
//             // Return shorter string
//             return (takeS1.size() <= takeS2.size()) ? takeS1 : takeS2;
//         }
//     }
//     string shortestCommonSupersequence(string str1, string str2) {
//         return solver(str1, str2, 0, 0);
//     }
// };


// top down
// ****gives tle as every "+" create a new string *****
// class Solution {
// public:
//     string solver(string &s1, string &s2, int i, int j, vector<vector<string>> &dp) {
//         int n = s1.size(), m = s2.size();

//         if (i == n) return s2.substr(j);
//         if (j == m) return s1.substr(i);

//         if (!dp[i][j].empty()) return dp[i][j];

//         if (s1[i] == s2[j]) {
//             dp[i][j] = s1[i] + solver(s1, s2, i + 1, j + 1, dp);
//         } else {
//             string takeS1 = s1[i] + solver(s1, s2, i + 1, j, dp);
//             string takeS2 = s2[j] + solver(s1, s2, i, j + 1, dp);
//             dp[i][j] = (takeS1.size() <= takeS2.size()) ? takeS1 : takeS2;
//         }

//         return dp[i][j];
//     }

//     string shortestCommonSupersequence(string str1, string str2) {
//         int n = str1.size(), m = str2.size();
//         vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
//         return solver(str1, str2, 0, 0, dp);
//     }
// };


//****OPTIMISED using m+n-lcs *******
//recursive
// class Solution {
// public:
//     // Recursive solver using LCS idea
//     string solver(string &s1, string &s2, int i = 0, int j = 0) {
//         int n = s1.size(), m = s2.size();

//         // Base cases
//         if (i == n) return s2.substr(j);
//         if (j == m) return s1.substr(i);

//         // If characters match, take once and move both
//         if (s1[i] == s2[j]) {
//             return s1[i] + solver(s1, s2, i + 1, j + 1);
//         } else {
//             // If characters don't match, take the path that gives longer LCS
//             // Compute remaining lengths recursively (like computing LCS)
//             int len1 = solver(s1, s2, i + 1, j).size();
//             int len2 = solver(s1, s2, i, j + 1).size();

//             if (len1 <= len2)
//                 return s1[i] + solver(s1, s2, i + 1, j);
//             else
//                 return s2[j] + solver(s1, s2, i, j + 1);
//         }
//     }

//     string shortestCommonSupersequence(string str1, string str2) {
//         return solver(str1, str2, 0, 0);
//     }
// };

