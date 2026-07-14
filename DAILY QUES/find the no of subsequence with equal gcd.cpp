https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14


class Solution {
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> t;

public:
    int solve(vector<int> &nums, int i, int first, int second) {
        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdsMatch = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }

        if (t[i][first][second] != -1)
            return t[i][first][second];

        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));

        // Summing up all the possibilities
        return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        t.assign(n + 1,
                 vector<vector<int>>(201,  //bcz gcd value can be b/w 0 to 200
                 vector<int>(201, -1)));

        return solve(nums, 0, 0, 0);
    }
};
