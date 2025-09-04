https://leetcode.com/problems/palindrome-partitioning-ii/


//recursive 
// class Solution {
// public:
//     bool isPalindrome(string& s, int i, int j) {
//         while(i < j) {
//             if(s[i] != s[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int solve(string& s, int i, int j) {
//         if(i >= j)
//             return 0;
//         if(isPalindrome(s, i, j))
//             return 0;

//         int res = INT_MAX;
//         for(int k = i; k <= j-1; k++) {
//             int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
//             res = min(res, temp);
//         }
//         return res;
//     }

//     int minCut(string s) {
//         int n = s.length();
//         return solve(s, 0, n-1);
//     }
// };





//top down 
// class Solution {
// public:
//     bool isPalindrome(const string &s, int i, int j) {
//         while (i < j) {
//             if (s[i] != s[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int solve(int i, int j, string &s, vector<vector<int>> &dp) {
//         if (i >= j) return 0;
//         if (isPalindrome(s, i, j)) return 0;
//         if (dp[i][j] != -1) return dp[i][j];

//         int res = INT_MAX;
//         for (int k = i; k <= j - 1; k++) {
//             int temp = 1 + solve(i, k, s, dp) + solve(k + 1, j, s, dp);
//             res = min(res, temp);
//         }
//         return dp[i][j] = res;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(0, n - 1, s, dp);
//     }
// };





//bottom up
class Solution {
public:
    int solver(const string &s) {
        int n = s.size();
        vector<vector<bool>> pal(n+1, vector<bool>(n+1, false));

        // Precompute palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n+1, INT_MAX);

        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (pal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }

    int minCut(string s) {
        return solver(s);
    }
};
