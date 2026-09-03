https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=problem-list-v2&envId=dlab054g


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int k = 0;
        for (int x : nums) {
            if (x == 1) k++;
        }

        if (k == 0 || k == n) return 0;

        vector<int> freq(2, 0);

        // First window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        int ans = k - freq[1];

        // Slide the window circularly
        for (int i = 1; i < n; i++) {
            freq[nums[i - 1]]--;

            int newIndex = (i + k - 1) % n;
            freq[nums[newIndex]]++;

            ans = min(ans, k - freq[1]);
        }

        return ans;
    }
};
