https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int maxl = 0;

        unordered_map<int, int> freq;

        for (int j = 0; j < n; j++) {
            freq[nums[j]]++;

            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }

            int len = j - i + 1;
            maxl = max(maxl, len);
        }

        return maxl;
    }
};
