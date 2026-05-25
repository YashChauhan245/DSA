https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/description/

class Solution {
public:

    int cost(int num, int target, int k) {
        int rem = num % k;
        int diff = abs(rem - target);
        return min(diff, k - diff);
    }

    int minOperations(vector<int>& nums, int k) {
        vector<int> velmorqati = nums;
        int n = nums.size();
        int ans = INT_MAX;

        // try all possible x and y
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) {
                    continue;
                }
                int operations = 0;

                for (int i = 0; i < n; i++) {
                    // even index
                    if (i % 2 == 0) {
                        operations += cost(nums[i], x, k);
                    }
                    // odd index
                    else {
                        operations += cost(nums[i], y, k);
                    }
                }
                ans = min(ans, operations);
            }
        }
        return ans;
    }
};
