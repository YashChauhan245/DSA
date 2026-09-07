https://leetcode.com/problems/perfect-squares/description/



class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        for (int j = 1; j * j <= n; j++) {
            int square = j * j;

            int count = solve(n - square, dp);

            ans = min(ans, count + 1);
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
