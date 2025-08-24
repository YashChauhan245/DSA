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


//bottom up 
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        // dp[i][j] = length of SCS for suffixes s1[i..] and s2[j..]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases (if one string is exhausted)
        for (int i = 0; i <= m; i++) dp[i][n] = m - i;
        for (int j = 0; j <= n; j++) dp[m][j] = n - j;

        // Fill table backwards
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // Reconstruct the SCS (no reverse needed now)
        string scs = "";
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                scs.push_back(s1[i]);
                i++, j++;
            } else if (dp[i + 1][j] <= dp[i][j + 1]) {
                scs.push_back(s1[i]);
                i++;
            } else {
                scs.push_back(s2[j]);
                j++;
            }
        }
        // Add remaining suffix
        while (i < m) scs.push_back(s1[i++]);
        while (j < n) scs.push_back(s2[j++]);

        return scs;
    }
};


