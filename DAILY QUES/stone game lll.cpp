https://leetcode.com/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03


class Solution {
public:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        int n = stoneValue.size();

        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            ans = max(ans, sum - solve(stoneValue, i + k + 1, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n+1, INT_MIN);

        int diff = solve(stoneValue, 0, dp);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};
