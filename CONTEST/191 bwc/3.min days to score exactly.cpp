https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/

class Solution {
public:
    int solve(int n, vector<int>& dp) {

        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = 1e9;

        for (int k = 1; k * (k + 1) / 2 <= n; k++) {

            int points = k * (k + 1) / 2;
            int rem = n - points;

            if (rem == 0) {
                ans = min(ans, k);
            }
            else {
                ans = min(ans, k + 1 + solve(rem, dp));
            }
        }

        return dp[n] = ans;
    }

    int minDays(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};
