https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10


// Pure Recursion
// T.C : O(2^n)
// S.C : O(n) -> recursion 

// class Solution {
// public:
//     int n;
//     int solve(int i, vector<int>& nums, int target) {

//         if(i == n - 1) {
//             return 0;
//         }

//         int result = INT_MIN;
//         for(int j = i + 1; j < n; j++) {
//             if(abs(nums[i] - nums[j]) <= target) {
//                 int temp = solve(j, nums, target);
//                 if(temp != INT_MIN) {
//                     result = max(result, 1 + temp);
//                 }
//             }
//         }
//         return result;
//     }


//     int maximumJumps(vector<int>& nums, int target) {
//         n = nums.size();
//         int result = solve(0, nums, target);
//         return result < 0 ? -1 : result;
//     }
// };


// Top Down DP
// T.C : O(n^2)
// S.C : O(n)

class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {
        if(i == n - 1) {
            return 0;
        }

        if(dp[i] != INT_MIN) {
            return dp[i];
        }

        int result = INT_MIN;
        for(int j = i + 1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int temp = solve(j, nums, target, dp);
                result = max(result, 1 + temp);
            }
        }
        return dp[i] = result;
    }


    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        int result = solve(0, nums, target, dp);
        return result < 0 ? -1 : result;
    }
};

