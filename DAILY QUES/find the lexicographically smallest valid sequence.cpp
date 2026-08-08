https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08


//RECURSION

// class Solution {
// public:

//     bool solve(string &word1, string &word2,int i, int j, int mismatch,vector<int> &ans) {

//         // matched
//         if (j == word2.size()) {
//             return true;
//         }

//         // No more characters in word1
//         if (i == word1.size()) {
//             return false;
//         }

//         // Characters match
//         if (word1[i] == word2[j]) {
//             ans.push_back(i);
//             if (solve(word1, word2, i + 1, j + 1, mismatch, ans)) {
//                 return true;
//             }
//             ans.pop_back();
//         }

//         // Characters don't match
//         else {

//             // Take this as our one mismatch
//             if (mismatch == 0) {

//                 ans.push_back(i);

//                 if (solve(word1, word2, i + 1, j + 1,1, ans)) {
//                     return true;
//                 }
//                 ans.pop_back();
//             }
//         }

//         // Skip word1[i]
//         if (solve(word1, word2, i + 1, j,mismatch, ans)) {
//             return true;
//         }
//         return false;
//     }

//     vector<int> validSequence(string word1, string word2) {
//         vector<int> ans;
//         solve(word1, word2, 0, 0, 0, ans);
//         return ans;
//     }
// };


//DP->TOP DOWN APPROACH

// class Solution {
// public:

//     bool solve(string &word1, string &word2,int i, int j, int mismatch,vector<vector<vector<int>>> &dp,
//                vector<int> &ans) {

//         // All characters of word2 are matched
//         if (j == word2.size())
//             return true;

//         // No characters left in word1
//         if (i == word1.size())
//             return false;

//         // Already calculated
//         if (dp[i][j][mismatch] != -1)
//             return dp[i][j][mismatch];

//         // Case 1: characters match -> take index
//         if (word1[i] == word2[j]) {
//             ans.push_back(i);
//             if (solve(word1, word2, i + 1, j + 1,mismatch, dp, ans))
//                 return dp[i][j][mismatch] = 1;//return 1 as we take dp as int vector
//             ans.pop_back();
//         }

//         // Case 2: mismatch -> take it as our one mismatch
//         else if (mismatch == 0) {
//             ans.push_back(i);
//             if (solve(word1, word2, i + 1, j + 1,1, dp, ans))
//                 return dp[i][j][mismatch] = 1;
//             ans.pop_back();
//         }

//         // Case 3: skip word1[i]
//         if (solve(word1, word2, i + 1, j,mismatch, dp, ans))
//             return dp[i][j][mismatch] = 1;

//         // No solution
//         return dp[i][j][mismatch] = 0;
//     }


//     vector<int> validSequence(string word1, string word2) {

//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(2, -1)));

//         vector<int> ans;

//         solve(word1, word2, 0, 0, 0, dp, ans);

//         return ans;
//     }
// };



//BEST-->using lc-3983

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 from which
        // word2[j...] can be matched exactly
        vector<int> last(m, -1);

        // Build suffix information from right to left
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // We can use at most ONE mismatch
        bool mismatchUsed = false;

        j = 0;

        // Greedily choose the smallest index
        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Case 1: characters match
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Case 2: characters mismatch
            else if (!mismatchUsed &&
                     (j == m - 1 || i < last[j + 1])) {

                // Use this as our one mismatch
                ans[j] = i;
                j++;

                mismatchUsed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
