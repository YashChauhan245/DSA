https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/


//recursive
// class Solution {
// public:
//     // solver returns {length, count}
//     pair<int,int> solver(vector<int>& nums, int i, int prev) {
//         // base case: end of array
//         if (i == nums.size()) {
//             return {0, 1}; // no elements → length=0, 1 way
//         }

//         // -------- OPTION 1: skip nums[i] --------
//         pair<int,int> skip = solver(nums, i + 1, prev);

//         // -------- OPTION 2: take nums[i] --------
//         pair<int,int> take = {0, 0};
//         if (prev == -1 || nums[i] > nums[prev]) {
//             auto next = solver(nums, i + 1, i);
//             take.first = 1 + next.first;   // add this element to LIS length
//             take.second = next.second;     // carry over the count
//         }

//         // -------- Compare results --------
//         if (take.first > skip.first) {
//             return take;   // taking gives longer LIS
//         } 
//         else if (take.first < skip.first) {
//             return skip;   // skipping gives longer LIS
//         } 
//         else {
//             // both give same LIS length → add counts
//             return {skip.first, skip.second + take.second};
//         }
//     }

//     int findNumberOfLIS(vector<int>& nums) {
//         return solver(nums, 0, -1).second; //**** .second → takes the second element of the pair → which is the number of LIS.
//     }
// };



//top down 

//class Solution {
// public:
//     pair<int,int> solver(vector<int>& nums, int i, int prev,
//                          vector<vector<pair<int,int>>>& dp) {
//         // base case
//         if (i == nums.size()) return {0, 1};

//         // check memo
//         if (dp[i][prev+1].first != -1) {
//             return dp[i][prev+1];
//         }

//         // ---- Option 1: skip ----
//         auto skip = solver(nums, i+1, prev, dp);

//         // ---- Option 2: take ----
//         pair<int,int> take = {0, 0};
//         if (prev == -1 || nums[i] > nums[prev]) {
//             auto next = solver(nums, i+1, i, dp);
//             take.first = 1 + next.first;
//             take.second = next.second;
//         }

//         // ---- Compare results ----
//         pair<int,int> ans;
//         if (take.first > skip.first) {
//             ans = take;
//         } else if (take.first < skip.first) {
//             ans = skip;
//         } else {
//             ans = {skip.first, skip.second + take.second};
//         }

//         return dp[i][prev+1] = ans; // memoize
//     }


//     int findNumberOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // dp[i][prev+1] stores pair{length, count}
//         vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n+1, {-1,-1}));
//         return solver(nums, 0, -1, dp).second;
//     }
// };




//bottom up 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // bottom-up solver
    pair<int,int> solver(vector<int>& nums) {
        int n = nums.size();

        // dp[i][prev+1] = {length, count}
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1, {0,0}));

        // base case: when i == n → length=0, ways=1
        for (int prev = -1; prev < n; prev++) {
            dp[n][prev+1] = {0,1};
        }

        // fill in reverse
        for (int i = n-1; i >= 0; i--) {
            for (int prev = i-1; prev >= -1; prev--) {

                // ---- skip ----
                auto skip = dp[i+1][prev+1];

                // ---- take ----
                pair<int,int> take = {0,0};
                if (prev == -1 || nums[i] > nums[prev]) {
                    auto nxt = dp[i+1][i+1];
                    take.first = 1 + nxt.first;
                    take.second = nxt.second;
                }

                // ---- choose better ----
                if (take.first > skip.first) {
                    dp[i][prev+1] = take;
                } else if (take.first < skip.first) {
                    dp[i][prev+1] = skip;
                } else {
                    dp[i][prev+1] = {skip.first, skip.second + take.second};
                }
            }
        }

        // final result for (i=0, prev=-1)
        return dp[0][0];
    }


    int findNumberOfLIS(vector<int>& nums) {
        // solver returns {length, count}, we want count
        return solver(nums).second; 
    }
};


