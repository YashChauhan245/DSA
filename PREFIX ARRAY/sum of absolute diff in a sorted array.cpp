https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=problem-list-v2&envId=prefix-sum


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftPrefix(n), rightPrefix(n);

        leftPrefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            leftPrefix[i] = leftPrefix[i - 1] + nums[i];

        rightPrefix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightPrefix[i] = rightPrefix[i + 1] + nums[i];

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;

            if (i > 0)
                left = nums[i] * i - leftPrefix[i - 1];

            if (i < n - 1)
                right = rightPrefix[i + 1] - nums[i] * (n - i - 1);

            ans[i] = left + right;
        }

        return ans;
    }
};
