https://leetcode.com/problems/burst-balloons/description/

//recursive
// class Solution {
// public:
//     int solver(vector<int>&nums,int l,int r){
//         if(l>r){
//             return 0;
//         }
//         int result=0;
//         for(int i=l;i<=r;i++){
//             int coins=(nums[l-1]*nums[i]*nums[r+1])+solver(nums,i+1,r)+solver(nums,l,i-1);
//             result=max(result,coins);
//         }
//         return result;
//     }
//     int maxCoins(vector<int>& nums) {
//         nums.insert(begin(nums),1);
//         nums.push_back(1);
//         return solver(nums,1,nums.size()-2);
//     }
// };


//top down 

// class Solution {
// public:
//     int solver(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
//         if(l > r) return 0;
//         if(dp[l][r] != -1) return dp[l][r]; 

//         int result = 0;
//         for(int i = l; i <= r; i++) {
//             int coins = nums[l-1] * nums[i] * nums[r+1]+ solver(nums, l, i-1, dp)      + solver(nums, i+1, r, dp);        
//             result = max(result, coins);
//         }
//         return dp[l][r] = result;  
//     }

//     int maxCoins(vector<int>& nums) {
//         nums.insert(nums.begin(), 1); 
//         nums.push_back(1);             
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solver(nums, 1, n-2, dp);
//     }
// };




//bottom  up 

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);  
        nums.push_back(1);           
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int l = n-2; l >= 1; l--) {
            for(int r = l; r <= n-2; r++) { // r >= l
                for(int i = l; i <= r; i++) {
                    int coins = nums[l-1] * nums[i] * nums[r+1] + dp[l][i-1] + dp[i+1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[1][n-2];
    }
};
