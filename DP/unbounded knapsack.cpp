https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//recursive
// class Solution {
//   public:
//     int solve(int idx, int capacity, vector<int>& val, vector<int>& wt) {
//         // Base case: no items left or no capacity left
//         if (idx == val.size() || capacity == 0) return 0;

//         // Option 1: skip current item
//         int skip = solve(idx + 1, capacity, val, wt);

//         // Option 2: take current item (if it fits) -> stay on same idx (unbounded)
//         int take = 0;
//         if (wt[idx] <= capacity) {
//             take = val[idx] + solve(idx, capacity - wt[idx], val, wt);
//         }

//         // Return best of take / skip
//         return max(take, skip);
//     }

//     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
//         return solve(0, capacity, val, wt);
//     }
// };




//memo 
// class Solution {
//   public:
//     int solve(int idx, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
//         // Base case
//         if (idx == val.size() || capacity == 0) return 0;

//         // Already computed
//         if (dp[idx][capacity] != -1) return dp[idx][capacity];

//         // Option 1: skip current item
//         int skip = solve(idx + 1, capacity, val, wt, dp);

//         // Option 2: take current item (if it fits)
//         int take = 0;
//         if (wt[idx] <= capacity) {
//             take = val[idx] + solve(idx, capacity - wt[idx], val, wt, dp);
//         }

//         // Store and return best
//         return dp[idx][capacity] = max(take, skip);
//     }

//     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
//         int n = val.size();
//         vector<vector<int>> dp(n+1, vector<int>(capacity + 1, -1));
//         return solve(0, capacity, val, wt, dp);
//     }
// };


//bottom up

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // dp[i][c] = max value using items from i..n-1 with capacity c
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c <= capacity; c++) {
                int skip = dp[i + 1][c];  // skip current item
                int take = 0;
                if (wt[i] <= c) {
                    take = val[i] + dp[i][c - wt[i]];  // take (stay on i because unbounded)
                }
                dp[i][c] = max(take, skip);
            }
        }

        return dp[0][capacity];
    }
};
