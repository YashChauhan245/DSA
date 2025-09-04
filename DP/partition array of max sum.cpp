https://leetcode.com/problems/partition-array-for-maximum-sum/description/


//recursive
// class Solution {
// public:
//     int n;

//     int solve(vector<int>& arr, int i, int k) {
//         // Base case
//         if(i >= n) {
//             return 0;
//         }

//         int result = 0;
//         int curr_max = -1;

//         // Try all partitions starting at i with length <= k
//         for(int j = i; j < n && j - i + 1 <= k; j++) {
//             curr_max = max(curr_max, arr[j]);
//             result = max(result, curr_max * (j - i + 1) + solve(arr, j + 1, k));
//         }

//         return result;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();
//         return solve(arr, 0, k);
//     }
// };





//top down 

// class Solution {
// public:
//     int n;
//     int solve(vector<int>& arr, int i, int k, vector<int>& dp) {
//         if(i >= n) return 0;
//         if(dp[i] != -1) return dp[i];

//         int result = 0;
//         int curr_max = -1;

//         for(int j = i; j < n && j - i + 1 <= k; j++) {
//             curr_max = max(curr_max, arr[j]);
//             result = max(result, curr_max * (j - i + 1) + solve(arr, j + 1, k, dp));
//         }
//         return dp[i] = result;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();
//         vector<int> dp(n+1, -1);  
//         return solve(arr, 0, k, dp);
//     }
// };




//bottom up 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); // dp[i] = max sum for subarray starting at i

        // Bottom-up, reverse loop
        for(int i = n - 1; i >= 0; i--) {
            int curr_max = -1;
            int result = 0;

            for(int j = i; j < n && j - i + 1 <= k; j++) {
                curr_max = max(curr_max, arr[j]);
                result = max(result, curr_max * (j - i + 1) + dp[j + 1]);
            }

            dp[i] = result;
        }

        return dp[0];
    }
};
