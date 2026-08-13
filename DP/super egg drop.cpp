https://leetcode.com/problems/super-egg-drop/description/


class Solution {
public:
    vector<vector<int>> dp;

    int solve(int k, int n) {
        // Base cases
        if (n == 0 || n == 1)
            return n;

        if (k == 1)
            return n;

        // Already calculated
        if (dp[k][n] != -1)
            return dp[k][n];

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Egg breaks
            int broken = solve(k - 1, mid - 1);

            // Egg doesn't break
            int notBroken = solve(k, n - mid);

            // Worst case for this mid
            int worst = 1 + max(broken, notBroken);

            ans = min(ans, worst);

            // Binary search
            if (broken > notBroken) {
                // Breaking case is worse,
                // so try a lower floor
                high = mid - 1;
            } 
            else {
                // Not-breaking case is worse,
                // so try a higher floor
                low = mid + 1;
            }
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        dp.assign(k + 1, vector<int>(n + 1, -1));

        return solve(k, n);
    }
};
