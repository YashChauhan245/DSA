https://leetcode.com/problems/target-sum/description/



//recursive
// class Solution {
// public:
//     int solve(vector<int>& nums, int target, int i, int sum) {
//         if (i == nums.size()) {
//             return sum == target ? 1 : 0;
//         }
//         // Choose +nums[i]
//         int plus = solve(nums, target, i + 1, sum + nums[i]);
//         // Choose -nums[i]
//         int minus = solve(nums, target, i + 1, sum - nums[i]);
//         return plus + minus;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(nums, target, 0, 0);
//     }
// };


//top down 

// class Solution {
// public:
//     int solve(vector<int>& nums, int i, int sum, int target, vector<vector<int>>& dp, int totalSum) {
//         if(i == nums.size()) {
//             return sum == target ? 1 : 0;
//         }
//         if(dp[sum + totalSum][i] != -1) return dp[sum + totalSum][i];
//         int plus = solve(nums, i + 1, sum + nums[i], target, dp, totalSum);
//         int minus = solve(nums, i + 1, sum - nums[i], target, dp, totalSum);
//         return dp[sum + totalSum][i] = plus + minus;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int totalSum = accumulate(nums.begin(), nums.end(), 0); // sum of all elements

//         // DP table: rows = possible sums (-totalSum to +totalSum), cols = indices
//         vector<vector<int>> dp(2 * totalSum + 1, vector<int>(n+1, -1));

//         return solve(nums, 0, 0, target, dp, totalSum);
//     }
// };



//bottom up 


class Solution {
public:
    int solver(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // DP table: dp[i][s] = number of ways to reach sum (s - totalSum) using numbers from i to n-1
        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, 0));

        // Base case: no numbers left → sum 0
        dp[n][totalSum] = 1;

        // Fill DP in reverse
        for (int i = n - 1; i >= 0; i--) {
            for (int s = 2 * totalSum; s >= 0; s--) {
                int plus = (s - nums[i] >= 0) ? dp[i + 1][s - nums[i]] : 0;
                int minus = (s + nums[i] <= 2 * totalSum) ? dp[i + 1][s + nums[i]] : 0;
                dp[i][s] = plus + minus;
            }
        }

        // Check if target is reachable
        if (target > totalSum || target < -totalSum) return 0;
        return dp[0][target + totalSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solver(nums, target);
    }
};
