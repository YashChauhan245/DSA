https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09

//no subarray can have a larger max than the array's globalMax,
// no subarray can have a smaller min than the globalMin
//as,we are allowed to overlap and repeat choices, the absolute best strategy is to just pick a subarray that contains both extremes, and just pick it k times

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int globalMin = *min_element(nums.begin(), nums.end());
        int globalMax = *max_element(nums.begin(), nums.end());

        long long bestSubarrayValue = globalMax - globalMin;

        return bestSubarrayValue * k;
    }
};
