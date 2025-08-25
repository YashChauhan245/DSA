https://leetcode.com/problems/wildcard-matching/solutions/

//recursive
// class Solution {
// public:
//     bool solver(string &s, string &p, int i, int j) {
//         int n = s.size();
//         int m = p.size();

//         if (i == n && j == m) return true;  //s=abc p=abc

//         // pattern finished but string not finished
//         if (j == m && i < n) return false;  //s=abc ,p=bc

//         // string finished but pattern still remains...
//         // s=abcd ,p=*abcd
//         if (i == n && j < m) {  
//             for (int k = j; k < m; k++) {
//                 if (p[k] != '*') return false;
//             }
//             return true;
//         }

//         // if characters match or pattern has '?'
//         if (s[i] == p[j] || p[j] == '?') {
//             return solver(s, p, i + 1, j + 1);
//         }

//         // if pattern has '*'
//         if (p[j] == '*') {
//             return solver(s, p, i, j + 1) || solver(s, p, i + 1, j);
//         }

//         else{
//             return false;
//         }
//     }

//     bool isMatch(string s, string p) {
//         return solver(s, p, 0, 0);
//     }
// };



//top down 

// class Solution {
// public:
//     bool solver(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
//         int n = s.size();
//         int m = p.size();

//         if (dp[i][j] != -1) return dp[i][j];

//         if (i == n && j == m) return dp[i][j] = true;     
//         if (j == m && i < n) return dp[i][j] = false;      
//         if (i == n && j < m) {                               
//             for (int k = j; k < m; k++) {
//                 if (p[k] != '*') return dp[i][j] = false;
//             }
//             return dp[i][j] = true;
//         }

//         if (s[i] == p[j] || p[j] == '?') {
//             return dp[i][j] = solver(s, p, i + 1, j + 1, dp);
//         }

//         if (p[j] == '*') {
//             return dp[i][j] = (solver(s, p, i, j + 1, dp) || solver(s, p, i + 1, j, dp));
//         }
//         return dp[i][j] = false;
//     }

//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return solver(s, p, 0, 0, dp);
//     }
// };



//bottom up 


class Solution {
public:
    bool solver(string &s, string &p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0)); // init with 0 (false)

        // Base case: empty string & empty pattern match
        dp[n][m] = 1;

        // Base case: if string is empty, check remaining pattern
        for (int j = m - 1; j >= 0; j--) {
            if (p[j] == '*')
                dp[n][j] = dp[n][j + 1];
            else
                break;
        }

        // Bottom-up filling in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } 
                else if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        return solver(s, p);
    }
};
