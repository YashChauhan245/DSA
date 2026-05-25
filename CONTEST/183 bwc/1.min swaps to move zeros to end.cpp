https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        // Count total zeros
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            }
        }
        // Count non-zero elements in last zeros positions
        int ans = 0;

        for (int i = n - zeros; i < n; i++) {
            if (nums[i] != 0) {
                ans++;
            }
        }
        return ans;
    }
};
