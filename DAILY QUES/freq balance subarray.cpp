https://leetcode.com/problems/frequency-balance-subarray/description/


class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int left = 0; left < n; left++) {

            // number -> frequency
            unordered_map<int, int> freq;

            // frequency -> how many numbers have this frequency
            unordered_map<int, int> freqCount;

            for (int right = left; right < n; right++) {

                int x = nums[right];

                int oldFreq = freq[x];

                // Remove old frequency contribution
                if (oldFreq > 0) {
                    freqCount[oldFreq]--;

                    if (freqCount[oldFreq] == 0) {
                        freqCount.erase(oldFreq);
                    }
                }

                // Increase frequency of current number
                freq[x]++;

                int newFreq = freq[x];

                // Add new frequency contribution
                freqCount[newFreq]++;

                // Case 1: only one distinct value
                if (freq.size() == 1) {
                    ans = max(ans, right - left + 1);
                    continue;
                }

                // Case 2: frequencies must be exactly {f, 2f}
                if (freqCount.size() == 2) {

                    auto it = freqCount.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;

                    int small = min(f1, f2);
                    int large = max(f1, f2);

                    if (large == 2 * small) {
                        ans = max(ans, right - left + 1);
                    }
                }
            }
        }

        return ans;
    }
};
