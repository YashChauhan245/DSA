https://leetcode.com/problems/jump-game-v/?envType=daily-question&envId=2026-05-25

class Solution {
public:
    int n;
    int solver(int i, vector<int>& arr, int d, vector<int>& dp) {

        // already calculated
        if (dp[i] != -1)
            return dp[i];

        int ans = 1; // count current index

        // move left
        for (int j = i - 1; j >= max(0, i - d); j--) {

            // stop if taller/equal element found
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solver(j, arr, d, dp));
        }

        // move right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {

            // stop if taller/equal element found
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solver(j, arr, d, dp));
        }
        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();

        // dp[i] = maximum jumps starting from i
        vector<int> dp(n, -1);

        int result = 1;

        // try starting from every index
        for (int i = 0; i < n; i++) {
            result = max(result, solver(i, arr, d, dp));
        }

        return result;
    }
};
