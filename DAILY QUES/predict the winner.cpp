https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01

class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        if (i == j) return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = nums[i] + min(solve(nums, i + 2, j),solve(nums, i + 1, j - 1));
        int takeRight = nums[j] + min(solve(nums, i + 1, j - 1),solve(nums, i, j - 2));
        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));

        int total = 0;
        for (int x : nums){
            total += x;
        }
        int player1 = solve(nums, 0, n - 1);
        int player2 = total - player1;

        return player1 >= player2;
    }
};
