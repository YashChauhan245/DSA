https://leetcode.com/problems/house-robber-ii/description/

//recursive
// class Solution {
// public:
//     int solve(vector<int>&nums, int s, int e){
//         //base case
//         if(s>e) return 0;
//         //include
//         int includeAns = nums[s] + solve(nums,s+2,e);
//         //exclude
//         int excludeAns = 0 + solve(nums,s+1,e);
//         return max(includeAns, excludeAns);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         //single element
//         if(n==1) return nums[0];
//         // Two linear cases because of circular houses:    
//         int includeAns = solve(nums, 0, n-2);
//         int excludeAns = solve(nums, 1, n-1);
//         int ans = max(includeAns, excludeAns);
//         return ans;
//     }
// };


//top down
// class Solution {
// public:
//     // Solve for linear range [s, e] using memoization
//     int solve(vector<int>& nums, int s, int e, vector<int>& dp) {
//         if (s > e) return 0;              // base case: no houses left
//         if (dp[s] != -1) return dp[s];   // return memoized result

//         int includeAns = nums[s] + solve(nums, s + 2, e, dp); // take current house
//         int excludeAns = solve(nums, s + 1, e, dp);           // skip current house

//         dp[s] = max(includeAns, excludeAns); // store result in dp
//         return dp[s];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];  // single house edge case

//         // Case 1: rob houses 0 → n-2
//         vector<int> dp1(n+1, -1);
//         int case1 = solve(nums, 0, n - 2, dp1);

//         // Case 2: rob houses 1 → n-1
//         vector<int> dp2(n+1, -1);
//         int case2 = solve(nums, 1, n - 1, dp2);

//         return max(case1, case2); // best of two linear ranges
//     }
// };



//bottom up 
// class Solution {
// public:
//     // Solve for linear range [s, e] using memoization
//     int solve(vector<int>& nums, int s, int e) {
//         int n=nums.size();
//         vector<int>dp(n+2,0);       
//         dp[n]=0;
//         dp[n-1]=0; 
//         dp[n-2]=0;
//         for(int i=e;i>=s;i--){
//             int includeAns = nums[i] + dp[i+ 2]; 
//             int excludeAns = dp[i + 1];          
//             dp[i] = max(includeAns, excludeAns);
//         }
//         return dp[s];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0]; 
//         int case1 = solve(nums, 0, n - 2);
//         int case2 = solve(nums, 1, n - 1);

//         return max(case1, case2);
//     }
// };



//space 
class Solution {
public:
    // Space-optimized linear House Robber for segment [start, end]
    int robLinear(vector<int>& nums, int start, int end) {
        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]
        int curr = 0;

        for(int i = end; i >= start; i--) {
            int take = nums[i] + next2;
            int skip = next1;
            curr = max(take, skip);

            // shift variables for next iteration
            next2 = next1;
            next1 = curr;
        }

        return curr; // max money starting at index 'start'
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // single house edge case

        // Case 1: rob houses 0 → n-2
        int case1 = robLinear(nums, 0, n-2);

        // Case 2: rob houses 1 → n-1
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2); // best of the two linear segments
    }
};
