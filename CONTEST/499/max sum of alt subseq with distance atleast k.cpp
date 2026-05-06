https://leetcode.com/problems/maximum-sum-of-alternating-subsequence-with-distance-at-least-k/

class Solution {
public:

    /*
        dir meaning:
        0 -> next picked number should be GREATER
        1 -> next picked number should be SMALLER
        2 -> direction not decided yet
    */

    long long solve(vector<int>& nums, int k,
                    int i, int prev, int dir,
                    vector<vector<vector<long long>>>& dp) {

        int n = nums.size();

        // reached end of array
        if(i >= n) {
            return 0;
        }

        // already computed
        if(dp[i][prev + 1][dir] != -1) {
            return dp[i][prev + 1][dir];
        }

        // Option 1: skip current element
        long long skip = solve(nums, k, i + 1, prev, dir, dp);

        // Option 2: take current element
        long long take = 0;

        // Case 1 -> first chosen element
        if(prev == -1) {

            take = nums[i] +
                   solve(nums, k, i + 1, i, 2, dp);
        }

        else {

            // elements must be at least k distance apart
            if(i - prev >= k) {

                // direction not fixed yet
                if(dir == 2) {

                    // increasing pair found
                    if(nums[i] > nums[prev]) {

                        take = nums[i] +
                               solve(nums, k, i + 1, i, 1, dp);
                    }

                    // decreasing pair found
                    else if(nums[i] < nums[prev]) {

                        take = nums[i] +
                               solve(nums, k, i + 1, i, 0, dp);
                    }
                }

                // we expect current number to be greater
                else if(dir == 0 && nums[i] > nums[prev]) {

                    take = nums[i] +
                           solve(nums, k, i + 1, i, 1, dp);
                }

                // we expect current number to be smaller
                else if(dir == 1 && nums[i] < nums[prev]) {

                    take = nums[i] +
                           solve(nums, k, i + 1, i, 0, dp);
                }
            }
        }

        // store and return answer
        return dp[i][prev + 1][dir] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums, int k) {

        int n = nums.size();

        /*
            dp[i][prev + 1][dir]

            i     -> current index
            prev  -> previously picked index
            dir   -> expected direction
        */

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(n + 1,
            vector<long long>(3, -1))
        );

        return solve(nums, k, 0, -1, 2, dp);
    }
};
