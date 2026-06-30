https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/


// class Solution {
// public:
//     vector<int> ans;
     
//     // calculate the sum of the subarray of length k starting at index i
//     int subarray(vector<int>& nums, int i, int k) {
//         int sum = 0;
//         for (int j = i; j < i + k; j++)
//             sum += nums[j];
//         return sum;
//     }
    
//     //tell what is the maximum sum possible from index i
//     int helper(vector<int>& nums, int i, int count, int k) {
//         if (count == 0)
//             return 0;

//         if (i > nums.size() - k)
//             return INT_MIN;

//         int take = subarray(nums, i, k) + helper(nums, i + k, count - 1, k);
//         int notTake = helper(nums, i + 1, count, k);

//         return max(take, notTake);
//     }
    

//     //for exploring all options
//     void solve(vector<int>& nums, int i, int count, int k) {
//         if (count == 0 || i > nums.size() - k)
//             return;

//         int takeI = subarray(nums, i, k) + helper(nums, i + k, count - 1, k);
//         int notTakeI = helper(nums, i + 1, count, k);

//         if (takeI >= notTakeI) {  //as we need lexicographically
//             ans.push_back(i);
//             solve(nums, i + k, count - 1, k);
//         } else {
//             solve(nums, i + 1, count, k);
//         }
//     }

//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         solve(nums, 0, 3, k);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> ans;

    int subarray(vector<int>& nums, int i, int k) {
        int sum = 0;
        for (int j = i; j < i + k; j++)
            sum += nums[j];
        return sum;
    }

    int helper(vector<int>& nums, int i, int count, int k,
               vector<vector<int>>& dp) {

        if (count == 0)
            return 0;

        if (i > nums.size() - k)
            return INT_MIN;

        if (dp[i][count] != -1)
            return dp[i][count];

        int take = subarray(nums, i, k) + helper(nums, i + k, count - 1, k, dp);
        int notTake = helper(nums, i + 1, count, k, dp);

        return dp[i][count] = max(take, notTake);
    }

    void solve(vector<int>& nums, int i, int count, int k,
               vector<vector<int>>& dp) {

        if (count == 0 || i > nums.size() - k)
            return;

        int take = subarray(nums, i, k) + helper(nums, i + k, count - 1, k, dp);
        int notTake = helper(nums, i + 1, count, k, dp);

        if (take >= notTake) {
            ans.push_back(i);
            solve(nums, i + k, count - 1, k, dp);
        } else {
            solve(nums, i + 1, count, k, dp);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));

        helper(nums, 0, 3, k, dp);
        solve(nums, 0, 3, k, dp);

        return ans;
    }
};
