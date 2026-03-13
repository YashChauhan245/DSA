https://leetcode.com/problems/house-robber-ii/description/


//recursive

// class Solution {
// public:
//     int solver(vector<int>& nums,int s,int e){
//         if(s>e){
//             return 0;
//         }
//         //case 
//         int take=nums[s]+solver(nums,s+2,e);
//         int skip=solver(nums,s+1,e);
//         return max(take,skip);
//     }

//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         //edge case
//         if(n==1){
//             return nums[0];
//         }
//         //cases
//         int firstindex_included=solver(nums,0,n-2); //0->n-2
//         int first_excluded=solver(nums,1,n-1);     //1-n-1
//         return max(firstindex_included,first_excluded);
//     }
// };



//top down 


class Solution {
public:

    int solve(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if (s > e) return 0;

        if (dp[s][e] != -1) return dp[s][e];

        int take = nums[s] + solve(nums, s + 2, e, dp);
        int skip = solve(nums, s + 1, e, dp);

        return dp[s][e] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        int case1 = solve(nums, 0, n-2, dp);
        int case2 = solve(nums, 1, n-1, dp);

        return max(case1, case2);
    }
};


//bottom up

// class Solution {
// public:

//     int solve(vector<int>& nums, int s, int e) {
//         int n = nums.size();
//         if (s > e) return 0;               
//         vector<int>dp(n+2,0);

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
