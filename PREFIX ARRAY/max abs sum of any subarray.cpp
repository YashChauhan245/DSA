https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

//Approach-(2 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        //Kadane's Algo for findig max subarray sum
        for(int i = 1; i < n; i++) {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        //Kadane's Algo for findig min subarray sum
        int minSubSum = nums[0];
        currSubSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum, currSubSum);
        }

        return max(maxSubSum, abs(minSubSum));
    }
};
